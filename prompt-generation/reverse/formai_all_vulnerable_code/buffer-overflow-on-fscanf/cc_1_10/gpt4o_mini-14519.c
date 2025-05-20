//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 256
#define MAX_BOOT_SCRIPTS 10

// Structure to hold boot script information
typedef struct {
    char path[MAX_PATH_LENGTH];
    int priority;
} BootScript;

// Function prototypes
void loadBootScripts(BootScript *scripts, int *count);
void sortBootScripts(BootScript *scripts, int count);
void executeBootScripts(BootScript *scripts, int count);
bool isExecutable(const char *path);

int main() {
    BootScript scripts[MAX_BOOT_SCRIPTS];
    int scriptCount = 0;

    // Load boot scripts
    loadBootScripts(scripts, &scriptCount);

    // Sort scripts by priority
    sortBootScripts(scripts, scriptCount);

    // Execute boot scripts based on sorted priority
    executeBootScripts(scripts, scriptCount);

    return 0;
}

void loadBootScripts(BootScript *scripts, int *count) {
    FILE *file = fopen("boot_scripts.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open boot_scripts.txt for reading.\n");
        exit(EXIT_FAILURE);
    }

    while (*count < MAX_BOOT_SCRIPTS && fscanf(file, "%s %d", scripts[*count].path, &scripts[*count].priority) == 2) {
        if (isExecutable(scripts[*count].path)) {
            (*count)++;
        } else {
            fprintf(stderr, "Skipping non-executable script: %s\n", scripts[*count].path);
        }
    }

    fclose(file);
}

void sortBootScripts(BootScript *scripts, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scripts[j].priority > scripts[j + 1].priority) {
                BootScript temp = scripts[j];
                scripts[j] = scripts[j + 1];
                scripts[j + 1] = temp;
            }
        }
    }
}

void executeBootScripts(BootScript *scripts, int count) {
    for (int i = 0; i < count; i++) {
        printf("Executing script: %s with priority: %d\n", scripts[i].path, scripts[i].priority);
        int status = system(scripts[i].path);
        if (status == -1) {
            perror("Error executing script");
        } else {
            printf("Script %s executed with exit status: %d\n", scripts[i].path, WEXITSTATUS(status));
        }
    }
}

bool isExecutable(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        return false; // File does not exist
    }
    return (st.st_mode & S_IXUSR); // Check if the file is executable by the user
}