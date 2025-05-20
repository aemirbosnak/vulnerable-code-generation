//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOOT_OPTIONS 5
#define MAX_OPTION_LENGTH 30

void display_options(char boot_options[MAX_BOOT_OPTIONS][MAX_OPTION_LENGTH], int count) {
    printf("\n🎉🎊 Welcome to the C System Boot Optimizer! 🎊🎉\n");
    printf("🌟 Here are your available boot options for a speedy start-up! 🌟\n");

    for (int i = 0; i < count; i++) {
        printf("🔧 %d: %s\n", i + 1, boot_options[i]);
    }

    printf("Please choose an option (1 - %d): ", count);
}

void optimize_boot_sequence(int chosen_option) {
    switch (chosen_option) {
        case 1:
            printf("\n🚀 Optimizing boot with 'Fast Boot' settings...\n");
            // Insert fictitious fast boot logic
            sleep(1);
            printf("🎉 Fast Boot enabled! Your system will start quickly now!\n");
            break;
        case 2:
            printf("\n🔄 Setting up 'Minimized Services' for faster boot...\n");
            // Insert fictitious minimized services logic
            sleep(1);
            printf("🎉 Minimized Services enabled! Say goodbye to unnecessary load!\n");
            break;
        case 3:
            printf("\n🔍 Running 'System Clean-up' for a sleeker boot process...\n");
            // Insert fictitious clean-up logic
            sleep(1);
            printf("🎉 System Clean-up complete! Your startup is now fresh and fast!\n");
            break;
        case 4:
            printf("\n🧰 Enabling 'Priority Boot' to optimize your hardware...\n");
            // Insert fictitious priority boot logic
            sleep(1);
            printf("🎉 Priority Boot enabled! Hardware resources are now prioritized!\n");
            break;
        case 5:
            printf("\n🎨 Customizing 'Boot Animation' for a delightful startup experience...\n");
            // Insert fictitious boot animation logic
            sleep(1);
            printf("🎉 Custom Boot Animation set! Enjoy a lively system startup!\n");
            break;
        default:
            printf("\n😱 Oops! That option isn't available. Please try again!\n");
            break;
    }
}

int main() {
    char boot_options[MAX_BOOT_OPTIONS][MAX_OPTION_LENGTH] = {
        "Fast Boot",
        "Minimized Services",
        "System Clean-up",
        "Priority Boot",
        "Custom Boot Animation"
    };

    int chosen_option = 0;

    while (chosen_option < 1 || chosen_option > MAX_BOOT_OPTIONS) {
        display_options(boot_options, MAX_BOOT_OPTIONS);
        
        if (scanf("%d", &chosen_option) != 1) {
            printf("\n😵 Invalid input! Please enter a number between 1 and %d.\n", MAX_BOOT_OPTIONS);
            while(getchar() != '\n'); // Clear invalid input
            chosen_option = 0; // Reset to allow for re-entry
        }
    }

    optimize_boot_sequence(chosen_option);
    
    printf("\n🌈 Thank you for using the C System Boot Optimizer! Have a fantastic day! 🌈\n");
    return 0;
}