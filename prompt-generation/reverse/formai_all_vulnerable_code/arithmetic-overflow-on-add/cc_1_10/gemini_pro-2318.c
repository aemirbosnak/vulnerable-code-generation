//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

static const char *input_file = "/proc/cmdline";
static const char *output_file = "/tmp/boot_optimizer.conf";

static const char *keywords[] = {
    "quiet",
    "pcie_aspm=",
    "pcie_aer=",
    "acpi_osi=",
    "cpuidle.governor=",
    "rcupdate.rcu_expedited=",
    "rcupdate.rcu_nobs=",
    "rcupdate.rcu_stall=",
    "governor=",
    "powersave.strict=",
    "sched_mc_power_savings=",
    "powersave_param=",
};

static const char *replacements[] = {
    "quiet loglevel=8",
    "pcie_aspm=force",
    "pcie_aer=off",
    "acpi_osi=!Linux",
    "cpuidle.governor=schedutil",
    "rcupdate.rcu_expedited=5",
    "rcupdate.rcu_nobs=2",
    "rcupdate.rcu_stall=10",
    "governor=performance",
    "powersave.strict=1",
    "sched_mc_power_savings=1",
    "powersave_param=",
};

static char *read_file(const char *filename, size_t *size)
{
    int fd;
    char *buffer;
    struct stat st;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;

    if (fstat(fd, &st) < 0) {
        close(fd);
        return NULL;
    }

    buffer = malloc(st.st_size + 1);
    if (buffer == NULL) {
        close(fd);
        return NULL;
    }

    if (read(fd, buffer, st.st_size) != st.st_size) {
        free(buffer);
        close(fd);
        return NULL;
    }

    close(fd);
    buffer[st.st_size] = '\0';
    *size = st.st_size;
    return buffer;
}

static void write_file(const char *filename, const char *buffer, size_t size)
{
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return;

    if (write(fd, buffer, size) != size)
        goto out;

out:
    close(fd);
}

static void optimize_cmdline(char *cmdline, size_t size)
{
    char *start, *end, *token;
    const char **keyword, **replacement;
    size_t i;

    start = cmdline;
    while (*start != '\0') {
        end = strchr(start, ' ');
        if (end == NULL)
            end = cmdline + size;

        token = malloc(end - start + 1);
        if (token == NULL)
            return;

        strncpy(token, start, end - start);
        token[end - start] = '\0';

        for (i = 0, keyword = keywords, replacement = replacements;
             i < ARRAY_SIZE(keywords);
             i++, keyword++, replacement++) {
            if (strncmp(token, *keyword, strlen(*keyword)) == 0) {
                free(token);
                token = malloc(strlen(*replacement) + 1);
                if (token == NULL)
                    return;

                strcpy(token, *replacement);
                break;
            }
        }

        memcpy(start, token, strlen(token));
        start += strlen(token);

        free(token);

        if (*start == ' ')
            start++;
    }
}

int main(int argc, char **argv)
{
    size_t size;
    char *cmdline;

    cmdline = read_file(input_file, &size);
    if (cmdline == NULL) {
        perror("read_file");
        return EXIT_FAILURE;
    }

    optimize_cmdline(cmdline, size);

    printf("Optimized kernel command line:\n");
    printf("%s\n", cmdline);

    write_file(output_file, cmdline, size);
    free(cmdline);

    return EXIT_SUCCESS;
}