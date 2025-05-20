//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXP 100
#define STRING_LENGTH 100

// Structure to hold experiment data
typedef struct {
    int id;
    char title[STRING_LENGTH];
    char researcher[STRING_LENGTH];
    char date[STRING_LENGTH];
} Experiment;

// Function prototypes
void addExperiment();
void viewExperiments();
void deleteExperiment();
void printExperiment(Experiment exp);
int getExperimentCount();

int main() {
    int choice;

    while (1) {
        printf("\n--- Experiment Database Menu ---\n");
        printf("1. Add Experiment\n");
        printf("2. View Experiments\n");
        printf("3. Delete Experiment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addExperiment();
                break;
            case 2:
                viewExperiments();
                break;
            case 3:
                deleteExperiment();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void addExperiment() {
    Experiment exp;
    FILE *fp;

    exp.id = getExperimentCount() + 1; // Incremental ID assignment
    printf("Enter Title: ");
    fgets(exp.title, STRING_LENGTH, stdin);
    exp.title[strcspn(exp.title, "\n")] = 0; // Remove newline character
    printf("Enter Researcher Name: ");
    fgets(exp.researcher, STRING_LENGTH, stdin);
    exp.researcher[strcspn(exp.researcher, "\n")] = 0; // Remove newline character
    printf("Enter Date (YYYY-MM-DD): ");
    fgets(exp.date, STRING_LENGTH, stdin);
    exp.date[strcspn(exp.date, "\n")] = 0; // Remove newline character

    fp = fopen("experiments.dat", "ab");
    if (fp == NULL) {
        perror("Unable to open file for writing");
        return;
    }
    
    fwrite(&exp, sizeof(Experiment), 1, fp);
    fclose(fp);
    printf("Experiment added successfully!\n");
}

void viewExperiments() {
    Experiment exp;
    FILE *fp;

    fp = fopen("experiments.dat", "rb");
    if (fp == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    printf("\n--- List of Experiments ---\n");
    while (fread(&exp, sizeof(Experiment), 1, fp)) {
        printExperiment(exp);
    }
    
    fclose(fp);
}

void deleteExperiment() {
    int id, count = 0;
    Experiment exp;
    FILE *fp, *temp;

    printf("Enter Experiment ID to delete: ");
    scanf("%d", &id);
    
    fp = fopen("experiments.dat", "rb");
    temp = fopen("temp.dat", "wb");
    if (fp == NULL || temp == NULL) {
        perror("Unable to open file");
        return;
    }

    int found = 0;
    while (fread(&exp, sizeof(Experiment), 1, fp)) {
        if (exp.id == id) {
            found = 1;
            printf("Deleting Experiment ID %d: %s\n", exp.id, exp.title);
            continue; // Skip this record to delete it
        }
        fwrite(&exp, sizeof(Experiment), 1, temp);
        count++;
    }

    fclose(fp);
    fclose(temp);
    remove("experiments.dat");
    rename("temp.dat", "experiments.dat");

    if (found) {
        printf("Experiment deleted successfully!\n");
    } else {
        printf("Experiment ID %d not found!\n", id);
    }
}

void printExperiment(Experiment exp) {
    printf("ID: %d\n", exp.id);
    printf("Title: %s\n", exp.title);
    printf("Researcher: %s\n", exp.researcher);
    printf("Date: %s\n", exp.date);
    printf("-----------------------\n");
}

int getExperimentCount() {
    Experiment exp;
    FILE *fp;
    int count = 0;

    fp = fopen("experiments.dat", "rb");
    if (fp == NULL) {
        return 0; // No records created yet
    }

    while (fread(&exp, sizeof(Experiment), 1, fp)) {
        count++;
    }

    fclose(fp);
    return count;
}