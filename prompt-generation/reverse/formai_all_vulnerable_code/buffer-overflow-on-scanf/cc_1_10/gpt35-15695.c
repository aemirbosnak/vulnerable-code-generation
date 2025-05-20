//FormAI DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTION_LENGTH 20

struct Option {
    char name[MAX_OPTION_LENGTH];
    int value;
};

struct Config {
    int boot_time;
    int num_options;
    struct Option *options;
};

void print_options(struct Config *config) {
    printf("Current options:\n");
    for (int i = 0; i < config->num_options; i++) {
        printf("%s: %d\n", config->options[i].name, config->options[i].value);
    }
}

void update_option(struct Config *config) {
    char option_name[MAX_OPTION_LENGTH];
    printf("Enter the name of the option you want to update:");
    scanf("%s", option_name);
    
    for (int i = 0; i < config->num_options; i++) {
        if (strcmp(config->options[i].name, option_name) == 0) {
            printf("Enter the new value:");
            scanf("%d", &config->options[i].value);
            printf("Updated %s to %d\n", option_name, config->options[i].value);
            return;
        }
    }
    
    printf("No such option found.\n");
}

int main(int argc, char **argv) {
    // Config defaults
    struct Config config;
    config.boot_time = 10;
    config.num_options = 3;
    struct Option options[3] = {
        {.name="option1", .value=1},
        {.name="option2", .value=2},
        {.name="option3", .value=3}
    };
    config.options = options;
    
    // Load config from file if given
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Error opening %s. Using defaults.\n", argv[1]);
        } else {
            char line[100];
            while (fgets(line, 100, fp)) {
                char *delimiter = strchr(line, '=');
                if (delimiter == NULL) continue;
                *delimiter = '\0';
                
                char *option_name = line;
                int option_value = atoi(delimiter+1);
                
                for (int i = 0; i < config.num_options; i++) {
                    if (strcmp(config.options[i].name, option_name) == 0) {
                        config.options[i].value = option_value;
                        break;
                    }
                }
            }
            
            fclose(fp);
        }
    }
    
    printf("Welcome to the boot optimizer.\n");
    print_options(&config);
    
    while (1) {
        printf("Enter a command (1=update, 2=quit):");
        int command;
        scanf("%d", &command);
        
        switch (command) {
            case 1:
                update_option(&config);
                print_options(&config);
                break;
            case 2:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Unknown command.\n");
        }
    }
    
    return 0;
}