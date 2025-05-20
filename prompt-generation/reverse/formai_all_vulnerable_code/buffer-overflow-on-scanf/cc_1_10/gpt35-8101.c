//FormAI DATASET v1.0 Category: System boot optimizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOT_TIME 60

void clear_console() {
    system("cls || clear");
}

void print_header() {
    clear_console();
    printf("C System Boot Optimizer\n\n");
}

void print_footer() {
    printf("\n\nPress any key to continue...");
    getchar();
    clear_console();
}

void print_loading_screen(int progress) {
    printf("\n Optimizing Boot Time... ", progress);
    printf("\n Loading... %d %%", progress);
    printf("\n\n Please wait for a moment...\n\n");
}

void optimize_boot_time() {
    int progress = 0;
    while (progress <= 100) {
        print_loading_screen(progress);
        progress += rand() % 10 + 1;
        if (progress > 100) {
            progress = 100;
        }
        for (int i = 0; i < (progress / 10); i++) {
            printf("=");
        }
        printf("\n");
        fflush(stdout);
        sleep(1);
        clear_console();
    }
}

bool start_optimization() {
    char input[10];
    printf(" Do you want to optimize the boot time? (y/n) ");
    scanf("%s", input);
    if (input[0] == 'y' || input[0] == 'Y') {
        return true;
    }
    return false;
}

int main() {
    srand(time(NULL));
    print_header();
    if (start_optimization()) {
        optimize_boot_time();
        printf("\n\n Boot optimization completed successfully!");
    } else {
        printf("\n\n Boot optimization cancelled by user!");
    }
    print_footer();
    return 0;
}