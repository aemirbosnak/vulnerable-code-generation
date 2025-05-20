//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CONFIGS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    char command[100];
} BootConfig;

BootConfig configs[MAX_CONFIGS];
int config_count = 0;

void add_config() {
    if (config_count >= MAX_CONFIGS) {
        printf("Maximum config limit reached!\n");
        return;
    }
    
    BootConfig new_config;

    printf("Enter the name of the configuration: ");
    scanf("%s", new_config.name);
    
    printf("Enter priority (higher numbers mean higher priority): ");
    scanf("%d", &new_config.priority);
    
    printf("Enter the command to execute on boot: ");
    scanf(" %[^\n]s", new_config.command);

    configs[config_count++] = new_config;
    printf("Configuration added successfully!\n");
}

void remove_config() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the configuration to remove: ");
    scanf("%s", name);

    for (int i = 0; i < config_count; i++) {
        if (strcmp(configs[i].name, name) == 0) {
            for (int j = i; j < config_count - 1; j++) {
                configs[j] = configs[j + 1];
            }
            config_count--;
            printf("Configuration removed successfully!\n");
            return;
        }
    }
    printf("Configuration not found!\n");
}

void list_configs() {
    printf("Boot Configurations:\n");
    for (int i = 0; i < config_count; i++) {
        printf("Name: %s, Priority: %d, Command: %s\n", configs[i].name, configs[i].priority, configs[i].command);
    }
}

void execute_commands() {
    // Sort configurations by priority
    for (int i = 0; i < config_count - 1; i++) {
        for (int j = 0; j < config_count - i - 1; j++) {
            if (configs[j].priority < configs[j + 1].priority) {
                BootConfig temp = configs[j];
                configs[j] = configs[j + 1];
                configs[j + 1] = temp;
            }
        }
    }

    printf("Executing boot commands in priority order:\n");
    for (int i = 0; i < config_count; i++) {
        printf("Executing: %s\n", configs[i].command);
        system(configs[i].command); // Use with caution
    }
}

void save_configs() {
    FILE *file = fopen("boot_configs.txt", "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    for (int i = 0; i < config_count; i++) {
        fprintf(file, "%s %d %s\n", configs[i].name, configs[i].priority, configs[i].command);
    }

    fclose(file);
    printf("Configurations saved to disk.\n");
}

void load_configs() {
    FILE *file = fopen("boot_configs.txt", "r");
    if (file == NULL) {
        printf("No existing configurations to load.\n");
        return; 
    }

    while (fscanf(file, "%s %d %[^\n]", configs[config_count].name, &configs[config_count].priority, configs[config_count].command) != EOF && config_count < MAX_CONFIGS) {
        config_count++;
    }

    fclose(file);
    printf("Configurations loaded from disk.\n");
}

void display_menu() {
    printf("\nBoot Optimizer Menu:\n");
    printf("1. Add Boot Configuration\n");
    printf("2. Remove Boot Configuration\n");
    printf("3. List Boot Configurations\n");
    printf("4. Execute Boot Configurations\n");
    printf("5. Save Configurations to Disk\n");
    printf("6. Load Configurations from Disk\n");
    printf("7. Exit\n");
}

int main() {
    load_configs();

    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_config();
                break;
            case 2:
                remove_config();
                break;
            case 3:
                list_configs();
                break;
            case 4:
                execute_commands();
                break;
            case 5:
                save_configs();
                break;
            case 6:
                load_configs();
                break;
            case 7:
                printf("Exiting the Boot Optimizer. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}