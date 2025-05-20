//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int bootPriority;
} BootEntry;

int totalEntries = 0;
BootEntry bootEntries[MAX_ENTRIES];

void addBootEntry(const char *name, int priority) {
    if (totalEntries < MAX_ENTRIES) {
        strcpy(bootEntries[totalEntries].name, name);
        bootEntries[totalEntries].bootPriority = priority;
        totalEntries++;
    } else {
        printf("Maximum boot entries reached!\n");
    }
}

void displayBootEntries() {
    printf("\nCurrent Boot Entries:\n");
    for (int i = 0; i < totalEntries; i++) {
        printf("Entry %d: %s (Priority: %d)\n", i+1, bootEntries[i].name, bootEntries[i].bootPriority);
    }
}

int compare(const void *a, const void *b) {
    BootEntry *entryA = (BootEntry *)a;
    BootEntry *entryB = (BootEntry *)b;
    return entryB->bootPriority - entryA->bootPriority; // Sort in descending order
}

void sortBootEntries() {
    qsort(bootEntries, totalEntries, sizeof(BootEntry), compare);
    printf("\nBoot entries sorted by priority!\n");
}

void saveBootEntriesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < totalEntries; i++) {
        fprintf(file, "%s,%d\n", bootEntries[i].name, bootEntries[i].bootPriority);
    }
    fclose(file);
    printf("\nBoot entries saved to %s!\n", filename);
}

void loadBootEntriesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char name[NAME_LENGTH];
        int priority;

        if (sscanf(line, "%49[^,],%d", name, &priority) == 2) {
            addBootEntry(name, priority);
        } else {
            printf("Invalid entry format in file: %s", line);
        }
    }
    fclose(file);
    printf("\nBoot entries loaded from %s!\n", filename);
}

void promptUserForEntries() {
    char name[NAME_LENGTH];
    int priority;

    while (1) {
        printf("\nEnter boot entry name (type 'exit' to stop): ");
        scanf("%49s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter boot priority (number): ");
        scanf("%d", &priority);

        addBootEntry(name, priority);
        printf("Boot entry '%s' added with priority %d!\n", name, priority);
    }
}

int main() {
    printf("Welcome to the C Boot Entry Optimizer!\n");
    printf("-------------------------------------------------\n");

    promptUserForEntries();
    
    displayBootEntries();

    sortBootEntries();
    
    char filename[NAME_LENGTH];
    printf("Enter filename to save boot entries: ");
    scanf("%49s", filename);
    saveBootEntriesToFile(filename);
    
    printf("Would you like to load boot entries from a file? (yes/no): ");
    char response[4];
    scanf("%3s", response);
    if (strcmp(response, "yes") == 0) {
        printf("Enter the filename to load: ");
        scanf("%49s", filename);
        loadBootEntriesFromFile(filename);
        displayBootEntries();
    }

    printf("Thank you for using the C Boot Entry Optimizer! Happy booting!\n");
    return 0;
}