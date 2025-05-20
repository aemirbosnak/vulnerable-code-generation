//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <time.h>

#define MAX_PROC 50
#define PROC_NAME_LEN 64
#define PID_LEN 10
#define FONT_SIZE 12
#define BG_COLOR "\x1b[48;5;233m" // LightGrey
#define FG_COLOR "\x1b[38;5;255m" // White
#define HIGH_COLOR "\x1b[38;5;160m" // BrightGreen
#define LOW_COLOR "\x1b[38;5;196m" // BrightCyan
#define RED_COLOR "\x1b[38;5;191m" // BrightRed

typedef struct {
    pid_t pid;
    char name[PROC_NAME_LEN];
    int memory_usage;
    int cpu_usage;
} Process;

Process processes[MAX_PROC];
int num_processes = 0;

void sigchld_handler(int sig) {
    int i, status;

    while ((i = waitpid(-1, &status, WNOHANG)) > 0) {
        for (int j = 0; j < num_processes; j++) {
            if (processes[j].pid == i) {
                processes[j].memory_usage = -1;
                processes[j].cpu_usage = -1;
                break;
            }
        }
    }
}

void print_header() {
    printf("%s%s\n", BG_COLOR, " Process Viewer - The Last Hope ");
    printf("%s%s\n", FG_COLOR, "----------------------------------");
    printf("%s%s\n", FG_COLOR, " PID   | Name               | Memory Usage | CPU Usage");
}

void print_process(Process p) {
    if (p.memory_usage > -1 && p.cpu_usage > -1) {
        printf("%s%s%10ld%s%s%11ld%s%s\n", FG_COLOR, "|", p.pid, "|", FG_COLOR, p.name, FG_COLOR, "|");
        printf("%s%s%12ld KB%s%s", LOW_COLOR, "|", p.memory_usage / 1024, "|");
        printf("%s%s%12d%%%s%s\n", HIGH_COLOR, "|", p.cpu_usage, "|", FG_COLOR);
    } else {
        printf("%s%s%10ld%s%s%11s%s\n", FG_COLOR, "|", p.pid, "|", FG_COLOR, "Unknown", FG_COLOR);
    }
}

void update_processes() {
    int i;

    num_processes = 0;

    FILE *ps = popen("ps -A -o pid,cmd,%mem,%cpu --sort=-%mem --format=%d %s", "w");

    if (!ps) {
        perror("Error opening pipe");
        return;
    }

    while (fscanf(ps, "%d %s %d %d", &processes[num_processes].pid, processes[num_processes].name, &processes[num_processes].memory_usage, &processes[num_processes].cpu_usage) > 0) {
        num_processes++;
    }

    pclose(ps);
}

int main() {
    sigset(SIGCHLD, sigchld_handler);

    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    printf("%s\n", BG_COLOR);

    while (1) {
        print_header();

        for (int i = 0; i < num_processes; i++) {
            print_process(processes[i]);
        }

        update_processes();

        usleep(500000);
    }

    return 0;
}