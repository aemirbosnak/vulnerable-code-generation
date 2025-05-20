//FormAI DATASET v1.0 Category: System boot optimizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_BOOT_TIME 30 //seconds

/*=====================================
    Helper Functions 
=====================================*/
void print_loading_bar(float progress) {
    int bar_width = 20;
    printf("[");
    int pos = bar_width * progress;
    for (int i = 0; i < bar_width; i++) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %d%%\r", (int)(progress * 100));
}

void run_startup_programs() {
    system("program1");
    system("program2");
    system("program3");
    system("program4");
}

/*=====================================
    Optimization Functions 
=====================================*/
void disable_unnecessary_services() {
    printf("Disabling unnecessary services...\n");
    system("service1 disable");
    system("service2 disable");
    system("service3 disable");
}

void defragment_disk() {
    printf("Defragmenting disk...\n");
    system("defrag -v");
}

/*=====================================
    Main Function 
=====================================*/
int main(int argc, char const *argv[]) {

    printf("Welcome to C System Boot Optimizer!\n");

    bool do_optimize = true;
    int boot_time = DEFAULT_BOOT_TIME; //seconds

    // Ask user for input
    char answer;
    printf("Do you want to optimize your boot time? (Y/N): ");
    scanf(" %c", &answer);
    if (answer != 'Y' && answer != 'y') {
        printf("Optimization cancelled.\n");
        do_optimize = false;
    }

    // Prompt user for boot time
    printf("Please enter your desired boot time in seconds (default is %d): ", DEFAULT_BOOT_TIME);
    scanf("%d", &boot_time);

    float progress = 0.0;
    int sleep_time = boot_time / 20; // update every 5% progress
    int total_steps = 3;
    int current_step = 1;

    if (do_optimize) {
        printf("Starting optimization...\n");
        // Step 1: disable unnecessary services
        disable_unnecessary_services();
        progress = (float)current_step / total_steps;
        print_loading_bar(progress);
        sleep(sleep_time);
        current_step++;

        // Step 2: defragment disk
        defragment_disk();
        progress = (float)current_step / total_steps;
        print_loading_bar(progress);
        sleep(sleep_time);
        current_step++;

        // Step 3: run startup programs
        run_startup_programs();
        progress = (float)current_step / total_steps;
        print_loading_bar(progress);
        sleep(sleep_time);
        printf("\nOptimization complete!\n");
    }

    return 0;
}