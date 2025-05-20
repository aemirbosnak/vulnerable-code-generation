//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_welcome_message() {
    printf("🎉 Welcome to the Happy Boot Optimizer! 🎉\n");
    printf("We're here to make your boot process a breeze! 🌈\n");
}

void show_optimizations() {
    printf("\nHere are some magical optimizations you can choose:\n");
    printf("1. Speed Up Boot Time 🌟\n");
    printf("2. Clean Up Startup Programs 🧹\n");
    printf("3. Enable Fast Boot 🏎️\n");
    printf("4. Configure Hibernation Settings 🌜\n");
    printf("5. Exit 🚪\n");
}

bool speed_up_boot() {
    printf("🔧 Speeding Up Boot Time...\n");
    // Simulated delay
    for (int i = 0; i < 3; i++) {
        printf("Optimizing... %d seconds passed\n", i + 1);
        sleep(1);
    }
    printf("✨ Boot time has been optimized! You're ready to go faster! 🚀\n");
    return true;
}

bool clean_up_startup() {
    printf("🧹 Cleaning Up Startup Programs...\n");
    
    // Simulate removing unwanted startup programs
    printf("Removing unnecessary programs...\n");
    sleep(2);
    printf("👾 Unwanted startup programs have been removed! Your system is breathing better! 🌬️\n");
    return true;
}

bool enable_fast_boot() {
    printf("🏎️ Enabling Fast Boot...\n");
    
    // Simulate enabling fast boot
    sleep(2);
    printf("🚀 Fast Boot is now enabled! Your system will start like a rocket! 🚀\n");
    return true;
}

bool configure_hibernation() {
    printf("🌜 Configuring Hibernation Settings...\n");
    // Simulate configuring hibernation
    sleep(2);
    printf("💤 Hibernation settings configured! Your system will take power naps! 💤\n");
    return true;
}

int main() {
    print_welcome_message();
    
    int choice;
    bool exit_program = false;

    while (!exit_program) {
        show_optimizations();
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                speed_up_boot();
                break;
            case 2:
                clean_up_startup();
                break;
            case 3:
                enable_fast_boot();
                break;
            case 4:
                configure_hibernation();
                break;
            case 5:
                printf("🚪 Thank you for using the Happy Boot Optimizer! Have a great day! 🌈\n");
                exit_program = true;
                break;
            default:
                printf("❌ Invalid choice! Please select a valid option (1-5).\n");
                break;
        }
    }

    return 0;
}