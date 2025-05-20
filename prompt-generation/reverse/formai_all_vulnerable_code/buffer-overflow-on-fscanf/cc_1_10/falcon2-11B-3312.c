//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_display() {
    int pid;
    char command[100];
    char user[20];
    char time[20];

    // Read process information from files
    FILE *pid_file = fopen("proc_pid.txt", "r");
    if (pid_file == NULL) {
        perror("Could not open proc_pid.txt");
        exit(1);
    }
    fscanf(pid_file, "%d", &pid);
    fclose(pid_file);

    FILE *cmd_file = fopen("proc_cmd.txt", "r");
    if (cmd_file == NULL) {
        perror("Could not open proc_cmd.txt");
        exit(1);
    }
    fscanf(cmd_file, "%s", command);
    fclose(cmd_file);

    FILE *user_file = fopen("proc_user.txt", "r");
    if (user_file == NULL) {
        perror("Could not open proc_user.txt");
        exit(1);
    }
    fscanf(user_file, "%s", user);
    fclose(user_file);

    FILE *time_file = fopen("proc_time.txt", "r");
    if (time_file == NULL) {
        perror("Could not open proc_time.txt");
        exit(1);
    }
    fscanf(time_file, "%s", time);
    fclose(time_file);

    printf("Process ID: %d\n", pid);
    printf("Command: %s\n", command);
    printf("User: %s\n", user);
    printf("Time: %s\n", time);
}

int main() {
    process_display();
    return 0;
}