//FormAI DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char* argv[]) {

    const char* process_name = argv[1];
    if (process_name == NULL) {
        printf("Usage: %s <process name>\n", argv[0]);
        exit(1);
    }

    const char* log_file_name = "resource_usage.log";
    FILE* log_file = fopen(log_file_name, "a");
    if (log_file == NULL) {
        printf("Failed to open log file '%s'.", log_file_name);
        exit(1);
    }

    pid_t pid = -1;
    FILE* ps_output = popen("ps -A -o pid,comm | awk '{print $1,$2}'","r");
    if (ps_output == NULL) {
        printf("Failed to execute 'ps' command.\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), ps_output)) {
        char* pid_str = strtok(line, " ");
        pid_t this_pid = atoi(pid_str);
        char* process_str = strtok(NULL, "\n");

        if (strcmp(process_str, process_name) == 0) {
            pid = this_pid;
            break;
        }
    }
    pclose(ps_output);

    if (pid == -1) {
        printf("Process '%s' not found.\n", process_name);
        exit(1);
    }

    printf("Monitoring resource usage of process '%s' with PID %d...\n", process_name, pid);

    while (1) {
        struct rusage res_usage;
        int status = getrusage(RUSAGE_CHILDREN, &res_usage);
        if (status != 0) {
            printf("Failed to get resource usage information for PID %d.", pid);
            exit(1);
        }

        long user_time_millis = res_usage.ru_utime.tv_sec * 1000 + res_usage.ru_utime.tv_usec / 1000;
        long system_time_millis = res_usage.ru_stime.tv_sec * 1000 + res_usage.ru_stime.tv_usec / 1000;
        long max_rss_kb = res_usage.ru_maxrss;

        fprintf(log_file, "%d,%ld,%ld,%ld\n", pid, user_time_millis, system_time_millis, max_rss_kb);
        fflush(log_file);

        usleep(500000);
    }

    fclose(log_file);
    return 0;
}