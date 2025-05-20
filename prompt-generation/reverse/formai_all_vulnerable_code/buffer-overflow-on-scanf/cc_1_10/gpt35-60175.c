//FormAI DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <string.h>

#define TERMINAL_GREEN "\033[0;32m"
#define TERMINAL_RESET "\033[0m"

void print_logo();
void print_menu();
void switch_on_lights();
void switch_off_lights();
void increase_temperature();
void decrease_temperature();
void lock_door();
void unlock_door();
void water_plants();
void check_status();
void clear_input();

int main() {
    print_logo();
    printf("\nWelcome to RetroHome Smart Automation System!\n\n");

    int option;

    while (1) {
        print_menu();
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                switch_on_lights();
                break;
            case 2:
                switch_off_lights();
                break;
            case 3:
                increase_temperature();
                break;
            case 4:
                decrease_temperature();
                break;
            case 5:
                lock_door();
                break;
            case 6:
                unlock_door();
                break;
            case 7:
                water_plants();
                break;
            case 8:
                check_status();
                break;
            case 9:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option!\n");
                break;
        }

        clear_input();
    }

    return 0;
}

void print_logo() {
    printf("\n");
    printf(" █████╗ ██╗   ██╗████████╗ ██████╗ ██████╗ ███╗   ██╗     ██╗███╗   ██╗██╗   ██╗██╗  ██╗\n");
    printf("██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗████╗  ██║     ██║████╗  ██║██║   ██║╚██╗██╔╝\n");
    printf("███████║██║   ██║   ██║   ██║   ██║██████╔╝██╔██╗ ██║     ██║██╔██╗ ██║██║   ██║ ╚███╔╝ \n");
    printf("██╔══██║██║   ██║   ██║   ██║   ██║██╔══██╗██║╚██╗██║██   ██║██║╚██╗██║██║   ██║ ██╔██╗ \n");
    printf("██║  ██║╚██████╔╝   ██║   ╚██████╔╝██║  ██║██║ ╚████║╚█████╔╝██║ ╚████║╚██████╔╝██╔╝ ██╗\n");
    printf("╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝\n");
    printf("\n");
}

void print_menu() {
    printf("\n");
    printf("╔═══════════════════════╗\n");
    printf("║ RetroHome Automation ║\n");
    printf("╚═══════════════════════╝\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Increase temperature\n");
    printf("4. Decrease temperature\n");
    printf("5. Lock door\n");
    printf("6. Unlock door\n");
    printf("7. Water plants\n");
    printf("8. Check status\n");
    printf("9. Exit\n");
}

void switch_on_lights() {
    printf(TERMINAL_GREEN "Turning on lights...\n" TERMINAL_RESET);
}

void switch_off_lights() {
    printf(TERMINAL_GREEN "Turning off lights...\n" TERMINAL_RESET);
}

void increase_temperature() {
    printf(TERMINAL_GREEN "Increasing temperature...\n" TERMINAL_RESET);
}

void decrease_temperature() {
    printf(TERMINAL_GREEN "Decreasing temperature...\n" TERMINAL_RESET);
}

void lock_door() {
    printf(TERMINAL_GREEN "Locking door...\n" TERMINAL_RESET);
}

void unlock_door() {
    printf(TERMINAL_GREEN "Unlocking door...\n" TERMINAL_RESET);
}

void water_plants() {
    printf(TERMINAL_GREEN "Watering plants...\n" TERMINAL_RESET);
}

void check_status() {
    printf(TERMINAL_GREEN "Checking status...\n" TERMINAL_RESET);
}

void clear_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}