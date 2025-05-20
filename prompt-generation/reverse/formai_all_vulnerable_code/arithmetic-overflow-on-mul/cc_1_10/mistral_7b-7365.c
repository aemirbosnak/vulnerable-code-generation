//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void print_cpu_usage(struct rusage *prev_usage, struct rusage *current_usage) {
    long long prev_utime = prev_usage->ru_utime.tv_sec * 1000 * 1000
                         + prev_usage->ru_utime.tv_usec;
    long long prev_stime = prev_usage->ru_stime.tv_sec * 1000 * 1000
                         + prev_usage->ru_stime.tv_usec;

    long long current_utime = current_usage->ru_utime.tv_sec * 1000 * 1000
                             + current_usage->ru_utime.tv_usec;
    long long current_stime = current_usage->ru_stime.tv_sec * 1000 * 1000
                             + current_usage->ru_stime.tv_usec;

    long long total_cpu_usage = (current_utime + current_stime) - (prev_utime + prev_stime);
    double percentage = ((double)total_cpu_usage / 1000000.0) * 100;

    printf("Parent process CPU usage: %.2f%%\n", percentage);
}

int main() {
    int status;
    pid_t child_pid;

    struct rusage prev_usage, current_usage;

    getrusage(RUSAGE_SELF, &prev_usage);

    child_pid = fork();

    if (child_pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (child_pid > 0) {
        getrusage(RUSAGE_SELF, &prev_usage);

        close(STDOUT_FILENO);
        dup2(open("/dev/null", O_WRONLY), STDOUT_FILENO);

        char *command[] = {"/bin/sleep", "5"};
        execvp(command[0], command);

        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    wait(&status);
    getrusage(RUSAGE_SELF, &current_usage);

    print_cpu_usage(&prev_usage, &current_usage);

    return 0;
}