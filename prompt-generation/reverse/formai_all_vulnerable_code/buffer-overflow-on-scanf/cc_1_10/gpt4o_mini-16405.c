//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>

#define PUZZLE_SIZE 5

void display_welcome_message() {
    printf("Welcome to the System Resource Monitor!\n");
    printf("To start, solve the puzzle to access the system resources.\n");
}

void generate_puzzle(int *num1, int *num2) {
    *num1 = rand() % 10;
    *num2 = rand() % 10;
}

void ask_puzzle(int num1, int num2) {
    int answer;
    printf("What is %d + %d? ", num1, num2);
    scanf("%d", &answer);
    if (answer == num1 + num2) {
        printf("Correct! Access granted.\n");
    } else {
        printf("Wrong answer! Try again.\n");
        exit(1);
    }
}

void monitor_cpu_memory() {
    struct sysinfo si;
    if (sysinfo(&si) < 0) {
        perror("sysinfo error");
        exit(1);
    }

    printf("Uptime: %ld seconds\n", si.uptime);
    printf("Total RAM: %ld MB\n", si.totalram / (1024 * 1024));
    printf("Free RAM: %ld MB\n", si.freeram / (1024 * 1024));
    printf("Total Processes: %d\n", si.procs);
}

void list_top_process_by_memory() {
    FILE *fp;
    char path[1024];
    
    printf("\nTop process by memory usage:\n");
    fp = popen("ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 6", "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        exit(1);
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);
    }
    pclose(fp);
}

int main() {
    int num1, num2;
    
    display_welcome_message();
    
    srand(time(NULL));
    generate_puzzle(&num1, &num2);
    ask_puzzle(num1, num2);
    
    while (1) {
        printf("\n--- Resource Monitor ---\n");
        monitor_cpu_memory();
        list_top_process_by_memory();
        
        printf("\nWould you like to refresh the resources? (1: Yes, 0: No): ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the monitor...\n");
            break;
        }
        
        sleep(5);  // Refresh every 5 seconds
    }
    
    return 0;
}