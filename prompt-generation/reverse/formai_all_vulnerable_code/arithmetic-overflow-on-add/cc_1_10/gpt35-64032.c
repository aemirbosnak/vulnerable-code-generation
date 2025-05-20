//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

void print_header() {
    printf("%s\n", "+------------------------------------------------+");
    printf("|     _______  _______  _______  _______        |");
    printf("|    (  ___  )(  ____ \(  ____ \(  ____ \       |");
    printf("|    | (   ) || (    \/| (    \/| (    \/       |");
    printf("|    | |   | || (__    | |      | (__           |");
    printf("|    | |   | ||  __)   | | ____ |  __)          |");
    printf("|    | |   | || (      | | \_  )| (             |");
    printf("|    | (___) || (____/\| (___) || (____/\       |");
    printf("|    (_______)(_______/(_______)(_______/       |");
    printf("|                                                |");
    printf("+------------------------------------------------+\n");
}

int main(int argc, char** argv) {
    struct tms t;
    long ticks_per_sec = sysconf(_SC_CLK_TCK);
    long last_user_time = 0, last_sys_time = 0;
    int last_cpu_usage = 0, cpu_usage;

    print_header();

    while(1) {
        if (times(&t) == -1) {
            perror("times");
            exit(1);
        }

        long curr_user_time = t.tms_utime;
        long curr_sys_time = t.tms_stime;

        long delta_user_time = curr_user_time - last_user_time;
        long delta_sys_time = curr_sys_time - last_sys_time;

        cpu_usage = (int)(100 * (delta_user_time + delta_sys_time) / ticks_per_sec);
        if (cpu_usage < 0) {
            cpu_usage = 0;
        } else if (cpu_usage > 100) {
            cpu_usage = 100;
        }

        printf("%c[1A", 27); // Move cursor up one line
        printf("%c[2K", 27); // Erase current line
        printf("CPU Usage: %d%%\n", cpu_usage);
        fflush(stdout);

        last_user_time = curr_user_time;
        last_sys_time = curr_sys_time;
        last_cpu_usage = cpu_usage;

        sleep(1);
    }

    return 0;
}