//FormAI DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void viewEntries();
void writeEntry();
void searchEntry();
void deleteEntry();
void menu();

struct entry {
    char date[11];
    char time[9];
    char note[200];
}; // structure to hold each diary entry

int main() {
    system("clear"); // clear terminal screen
    menu(); // display menu
    return 0;
}

void viewEntries() {
    system("clear"); // clear terminal screen
    FILE *fp;
    struct entry e;
    fp = fopen("diary.dat", "rb");
    if (fp == NULL) {
        printf("No diary entries found\n");
        menu();
        return;
    }
    printf("Diary Entries:\n");
    printf("Date\t\tTime\tNote\n");
    while (fread(&e, sizeof(struct entry), 1, fp)){
        printf("%s\t%s\t%s\n", e.date, e.time, e.note);
    }
    fclose(fp);
    printf("\nPress enter to return to the menu\n");
    getchar(); // wait for user to press enter
    menu();
}

void writeEntry() {
    system("clear"); // clear terminal screen
    FILE *fp;
    struct entry e;
    time_t t;
    struct tm tm;
    t = time(NULL);
    localtime_r(&t, &tm); // get current time
    strftime(e.date, 11, "%d-%m-%Y", &tm); // format date
    strftime(e.time, 9, "%H:%M:%S", &tm); // format time
    printf("Enter note (max 200 characters):\n");
    getchar(); // clear input buffer
    fgets(e.note, 200, stdin); // get note from user
    fp = fopen("diary.dat", "ab");
    if (fp == NULL) {
        printf("Error writing to diary file\n");
        menu();
        return;
    }
    fwrite(&e, sizeof(struct entry), 1, fp); // write entry to file
    fclose(fp);
    printf("\nNote Written Successfully!\n");
    printf("\nPress enter to return to the menu\n");
    getchar(); // wait for user to press enter
    menu();
}

void searchEntry() {
    system("clear"); // clear terminal screen
    FILE *fp;
    struct entry e;
    char sdate[11];
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", sdate);
    fp = fopen("diary.dat", "rb");
    if (fp == NULL) {
        printf("No diary entries found\n");
        menu();
        return;
    }
    printf("\nSearch Results:\n");
    printf("Date\t\tTime\tNote\n");
    while (fread(&e, sizeof(struct entry), 1, fp)){
        if (strcmp(e.date, sdate) == 0) {
            printf("%s\t%s\t%s\n", e.date, e.time, e.note);
        }
    }
    fclose(fp);
    printf("\nPress enter to return to the menu\n");
    getchar(); // wait for user to press enter
    menu();
}

void deleteEntry() {
    system("clear"); // clear terminal screen
    FILE *fp, *ft;
    struct entry e;
    char sdate[11];
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", sdate);
    fp = fopen("diary.dat", "rb");
    if (fp == NULL) {
        printf("No diary entries found\n");
        menu();
        return;
    }
    ft = fopen("temp.dat", "wb"); // create temporary file
    while (fread(&e, sizeof(struct entry), 1, fp)){
        if (strcmp(e.date, sdate) != 0) {
            fwrite(&e, sizeof(struct entry), 1, ft); // write non-matching entries to temporary file
        }
    }
    fclose(fp);
    fclose(ft);
    remove("diary.dat"); // remove original file
    rename("temp.dat", "diary.dat"); // rename temporary file to original file
    printf("\nNote Deleted Successfully!\n");
    printf("\nPress enter to return to the menu\n");
    getchar(); // wait for user to press enter
    menu();
}

void menu() {
    system("clear"); // clear terminal screen
    printf("  Digital Diary\n");
    printf("------------------\n");
    printf("1. View All Entries\n");
    printf("2. Write An Entry\n");
    printf("3. Search By Date\n");
    printf("4. Delete An Entry\n");
    printf("5. Exit\n");
    printf("------------------\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            viewEntries();
            break;
        case 2:
            writeEntry();
            break;
        case 3:
            searchEntry();
            break;
        case 4:
            deleteEntry();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            menu();
            break;
    }
}