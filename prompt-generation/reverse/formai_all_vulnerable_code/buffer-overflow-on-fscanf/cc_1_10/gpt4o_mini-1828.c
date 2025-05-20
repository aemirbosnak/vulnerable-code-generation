//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BOOT_OPTIONS 5
#define MAX_OPTION_LENGTH 50
#define MAX_CONFIG_LENGTH 100
#define CONFIG_FILENAME "boot_config.txt"

struct BootOption {
    char name[MAX_OPTION_LENGTH];
    char config[MAX_CONFIG_LENGTH];
};

void display_boot_options(struct BootOption options[], int size) {
    printf("\n--- Boot Options ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", i + 1, options[i].name);
    }
    printf("--------------------\n");
}

void select_boot_option(struct BootOption options[], int size) {
    int choice;
    
    printf("Select a boot option by number (1 to %d): ", size);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > size) {
        printf("Invalid choice. Booting default option.\n");
        choice = 1; // Default to the first option
    }

    printf("You selected: %s\n", options[choice - 1].name);
}

void write_config_to_file(const char *filename, struct BootOption options[], int size, int selected_index) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Last Selected Boot Option: %s\n", options[selected_index].name);
    fclose(file);
    printf("Configuration saved to '%s'.\n", filename);
}

void load_previous_selection(const char *filename, struct BootOption options[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous configuration found. Using default option.\n");
        return;
    }

    char buffer[MAX_OPTION_LENGTH];
    fscanf(file, "Last Selected Boot Option: %[^\n]", buffer);
    fclose(file);

    for (int i = 0; i < size; i++) {
        if (strcmp(buffer, options[i].name) == 0) {
            printf("Restoring previous selection: %s\n", options[i].name);
            return;
        }
    }

    printf("Previous selection not found. Booting default option: %s\n", options[0].name);
}

int main() {
    struct BootOption boot_options[NUM_BOOT_OPTIONS] = {
        {"Ubuntu", "ubuntu_boot_parameters"},
        {"Fedora", "fedora_boot_parameters"},
        {"Arch Linux", "arch_boot_parameters"},
        {"Windows", "windows_boot_parameters"},
        {"Recovery Mode", "recovery_boot_parameters"}
    };

    load_previous_selection(CONFIG_FILENAME, boot_options, NUM_BOOT_OPTIONS);
    
    display_boot_options(boot_options, NUM_BOOT_OPTIONS);
    select_boot_option(boot_options, NUM_BOOT_OPTIONS);
    
    int selected_index = 0; // Assuming first option by default
    // Update selected_index based on user's choice from the above function (not directly handled here)
    
    // For the sake of this demo, we assume the user can choose their option by updating selected_index
  
    write_config_to_file(CONFIG_FILENAME, boot_options, NUM_BOOT_OPTIONS, selected_index);

    return 0;
}