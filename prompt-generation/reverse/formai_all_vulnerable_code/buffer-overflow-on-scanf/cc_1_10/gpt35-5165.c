//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct log_entry {
    char datetime[20];
    char severity[10];
    char message[100];
};

void display_menu() {
    printf("\nMenu:\n");
    printf("1. View all log entries\n");
    printf("2. View log entries by severity\n");
    printf("3. Search log entries by message\n");
    printf("4. Exit\n");
}

int count_entries(FILE* fp) {
    int count = 0;
    char line[150];
    while (fgets(line, sizeof(line), fp)) {
        count++;
    }
    rewind(fp);
    return count;
}

void view_all_entries(struct log_entry* entries, int count) {
    printf("\nAll log entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %s", entries[i].datetime, entries[i].severity, entries[i].message);
    }
}

void view_entries_by_severity(struct log_entry* entries, int count, char* severity) {
    printf("\nLog entries with severity %s:\n", severity);
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].severity, severity) == 0) {
            printf("%s %s %s", entries[i].datetime, entries[i].severity, entries[i].message);
        }
    }
}

void search_entries_by_message(struct log_entry* entries, int count, char* message) {
    printf("\nLog entries containing \"%s\":\n", message);
    for (int i = 0; i < count; i++) {
        if (strstr(entries[i].message, message)) {
            printf("%s %s %s", entries[i].datetime, entries[i].severity, entries[i].message);
        }
    }
}

int main() {
    char filename[50];
    printf("Enter log file name: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file!");
        return 1;
    }
    int count = count_entries(fp);
    struct log_entry* entries = (struct log_entry*) malloc(count * sizeof(struct log_entry));
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%s %s %[^\n]", entries[i].datetime, entries[i].severity, entries[i].message);
    }
    fclose(fp);
    int choice = 0;
    while (choice != 4) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_all_entries(entries, count);
                break;
            case 2:
                printf("Enter severity level: ");
                char severity[10];
                scanf("%s", severity);
                view_entries_by_severity(entries, count, severity);
                break;
            case 3:
                printf("Enter search string: ");
                char message[100];
                scanf(" %[^\n]", message);
                search_entries_by_message(entries, count, message);
                break;
            case 4:
                printf("Exiting program. Thank you!");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    free(entries);
    return 0;
}