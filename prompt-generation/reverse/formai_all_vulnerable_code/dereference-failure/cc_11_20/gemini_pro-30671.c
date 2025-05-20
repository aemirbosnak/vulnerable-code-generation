//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

// Define colors for terminal output
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"

// Define process states
#define STATE_RUNNING "R"
#define STATE_SLEEPING "S"
#define STATE_STOPPED "T"
#define STATE_ZOMBIE "Z"

// Entry point of the program
int main() {
    // Get system information
    struct utsname system_info;
    uname(&system_info);

    // Print system information
    printf("System: %s %s %s %s\n", system_info.sysname, system_info.release, system_info.version, system_info.machine);
    printf("Hostname: %s\n", system_info.nodename);

    // Print current user information
    struct passwd *pw = getpwuid(getuid());
    printf("User: %s (%d)\n", pw->pw_name, pw->pw_uid);

    // Print current group information
    struct group *gr = getgrgid(getgid());
    printf("Group: %s (%d)\n", gr->gr_name, gr->gr_gid);

    // Get list of processes
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc");
        exit(EXIT_FAILURE);
    }

    // Iterate over processes
    struct dirent *proc_entry;
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        // Check if entry is a valid process directory
        if (!isdigit(proc_entry->d_name[0])) {
            continue;
        }

        // Get process information
        int pid = atoi(proc_entry->d_name);
        char path[256];
        snprintf(path, 256, "/proc/%d/stat", pid);
        FILE *stat_file = fopen(path, "r");
        if (stat_file == NULL) {
            perror("Error opening stat file");
            exit(EXIT_FAILURE);
        }

        char line[1024];
        if (fgets(line, 1024, stat_file) == NULL) {
            perror("Error reading stat file");
            exit(EXIT_FAILURE);
        }
        fclose(stat_file);

        // Parse process information
        char *fields[25];
        int field_count = 0;
        char *field = strtok(line, " ");
        while (field != NULL) {
            fields[field_count++] = field;
            field = strtok(NULL, " ");
        }

        // Get process name
        char *name = fields[1];

        // Get process state
        char state = fields[2][0];
        switch (state) {
            case 'R':
                state = STATE_RUNNING;
                break;
            case 'S':
                state = STATE_SLEEPING;
                break;
            case 'T':
                state = STATE_STOPPED;
                break;
            case 'Z':
                state = STATE_ZOMBIE;
                break;
            default:
                state = '?';
        }

        // Get process user and group
        int uid = atoi(fields[5]);
        int gid = atoi(fields[6]);
        struct passwd *pw = getpwuid(uid);
        struct group *gr = getgrgid(gid);

        // Get process start time
        time_t start_time = atol(fields[21]);
        char *start_time_str = ctime(&start_time);

        // Print process information
        printf("%5d %-16s %-5s %-8s %-8s %.24s\n", pid, name, state, pw->pw_name, gr->gr_name, start_time_str);
    }

    // Close process directory
    closedir(proc_dir);

    return EXIT_SUCCESS;
}