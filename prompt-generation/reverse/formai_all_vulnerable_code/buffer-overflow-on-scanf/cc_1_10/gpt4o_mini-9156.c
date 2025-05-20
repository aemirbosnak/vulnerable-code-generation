//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The grand banners of the realm
#define MAX_BOOT_OPTIONS 10
#define OPTION_NAME_LENGTH 50

// The noble structure to hold our boot choices
typedef struct {
    char name[OPTION_NAME_LENGTH];
    bool selected;
} BootOption;

// The glorious array of boot options
BootOption bootOptions[MAX_BOOT_OPTIONS];
int optionCount = 0;

// The fabled function to display the illustrious boot menu
void displayBootMenu() {
    printf("=== The Royal Boot Menu ===\n");
    for (int i = 0; i < optionCount; i++) {
        printf("%s [%s]\n", bootOptions[i].name, bootOptions[i].selected ? "✓" : " ");
    }
}

// The gallant function to select a boot option
void selectBootOption(int index) {
    if (index >= 0 && index < optionCount) {
        bootOptions[index].selected = !bootOptions[index].selected;
    } else {
        printf("Alas! The selection is out of bounds!\n");
    }
}

// The wise sage function to optimize the boot options
void optimizeBootOptions() {
    printf("Ah, the time has come to optimize thy chosen paths...\n");
    int optimizedCount = 0;
    
    for (int i = 0; i < optionCount; i++) {
        if (bootOptions[i].selected) {
            bootOptions[optimizedCount++] = bootOptions[i];
        }
    }
    
    optionCount = optimizedCount;
    printf("Thy boot options hath been optimized!\n");
}

// The brave knight function to add boot options to the menu
void addBootOption(const char *name) {
    if (optionCount < MAX_BOOT_OPTIONS) {
        snprintf(bootOptions[optionCount].name, OPTION_NAME_LENGTH, "%s", name);
        bootOptions[optionCount].selected = false;
        optionCount++;
        printf("A new boot option hath been added: %s!\n", name);
    } else {
        printf("The boot option list is full! The castle hath no more room!\n");
    }
}

// The noble function to execute the selected boot options
void executeBootOptions() {
    printf("The time has come! Thy selected options shall now commence their journey:\n");
    for (int i = 0; i < optionCount; i++) {
        if (bootOptions[i].selected) {
            printf("Commencing the quest for: %s\n", bootOptions[i].name);
        }
    }
    printf("All selected boot options hast been executed! Huzzah!\n");
}

// The chivalrous main function, the heart of the realm
int main() {
    // Initializing the boot options
    addBootOption("Linux Kernel - Noble steed of stability");
    addBootOption("Ubuntu - A gentle embrace for the weary traveler");
    addBootOption("Arch - The path less traveled");
    addBootOption("Windows - A portal to the foreign land");
    addBootOption("Gentoo - The artisan's choice");

    // Displaying the menu
    displayBootMenu();

    // Selecting boot options
    printf("Select the options (0-4), type -1 to finish:\n");
    int choice;
    while (true) {
        scanf("%d", &choice);
        if (choice == -1) break;
        selectBootOption(choice);
    }

    // Optimize maidens of boot choices
    optimizeBootOptions();

    // Display the optimized list
    displayBootMenu();

    // Enact the commands of the Boot Realm
    executeBootOptions();

    return 0;
}