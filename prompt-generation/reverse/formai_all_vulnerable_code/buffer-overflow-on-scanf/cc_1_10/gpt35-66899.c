//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
/* The Ada Lovelace Digital Diary example program
   This program allows users to record and display their thoughts and experiences seamlessly.
   The diary entries are saved in '.txt' format in the same directory as the program. 
   The program is user-friendly with various built-in functions that allows comfortable user experience. 
   The program was inspired by Ada Lovelace, the first computer programmer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_FILE_LENGTH 1000

// Function prototype declaration
void displayMenu();
void create();
void read();
void edit();
void delete();
void search();
void quit();

int main() {
    displayMenu();
    return 0;
}

// Display the main menu
void displayMenu() {
    char choice;
    printf("Welcome to your Digital Diary!\n");
    printf("Choose one of the following options:\n");
    printf("1. Create new entry\n");
    printf("2. Read existing entry\n");
    printf("3. Edit existing entry\n");
    printf("4. Delete existing entry\n");
    printf("5. Search existing entry\n");
    printf("6. Quit\n");
    scanf("%c", &choice);
    switch(choice) {
        case '1':
            create();
            break;
        case '2':
            read();
            break;
        case '3':
            edit();
            break;
        case '4':
            delete();
            break;
        case '5':
            search();
            break;
        case '6':
            quit();
            break;
        default:
            printf("Invalid input. Please try again.\n");
            displayMenu();
    }
}

// Create a new diary entry
void create() {
    FILE *fp;
    char date[20], entry[MAX_ENTRY_LENGTH], file[MAX_FILE_LENGTH];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    sprintf(file, "%02d%02d%d.txt", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("Enter your diary entry (maximum 1000 characters):\n");
    getchar();  // Ensure no '\n' character gets stored
    fgets(entry, sizeof(entry), stdin);
    fp = fopen(file, "a+");
    fprintf(fp, "Date: %s\n", date);
    fprintf(fp, "%s\n", entry);
    fclose(fp);
    printf("%s entry created successfully.\n", date);
    displayMenu();
}

// Read an existing diary entry
void read() {
    FILE *fp;
    char fileName[MAX_FILE_LENGTH], line[MAX_ENTRY_LENGTH];
    printf("Enter the name of the file you want to read (ddmmyyyy.txt):\n");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");
    if(fp) {
        while(fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
    else {
        printf("Cannot find file.\n");
    }
    displayMenu();
}

// Edit an existing diary entry
void edit() {
    FILE *fp, *temp;
    char fileName[MAX_FILE_LENGTH], line[MAX_ENTRY_LENGTH], date[20], entry[MAX_ENTRY_LENGTH], file[MAX_FILE_LENGTH], tempFile[] = "temp.txt";
    int flag = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    sprintf(file, "%02d%02d%d.txt", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("Enter the name of the file you want to edit (ddmmyyyy.txt):\n");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");
    temp = fopen(tempFile, "w");
    if(fp && temp) {
        while(fgets(line, sizeof(line), fp)) {
            if(strncmp(line, "Date:", 5) == 0 && flag == 0) {
                if(strcmp(date, strtok(line+5, "\n")) == 0) {
                    flag = 1;
                    printf("Enter your edited diary entry:\n");
                    getchar();  // Ensure no '\n' character gets stored
                    fgets(entry, sizeof(entry), stdin);
                    fprintf(temp, "Date: %s\n%s\n", date, entry);
                    printf("%s entry edited successfully.\n", date);
                }
                else {
                    fprintf(temp, "%s", line);
                }
            }
            else {
                fprintf(temp, "%s", line);
            }
        }
        if(flag == 0) {
            printf("%s entry not found. Creating new entry under today's date.\n", date);
            create();
        }
        fclose(fp);
        fclose(temp);
        remove(fileName);
        rename(tempFile, fileName);
    }
    else {
        printf("Cannot find file.\n");
    }
    displayMenu();
}

// Delete an existing diary entry
void delete() {
    FILE *fp, *temp;
    char fileName[MAX_FILE_LENGTH], line[MAX_ENTRY_LENGTH], date[20], tempFile[] = "temp.txt";
    int flag = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("Enter the name of the file you want to delete (ddmmyyyy.txt):\n");
    scanf("%s", fileName);
    fp = fopen(fileName, "r");
    temp = fopen(tempFile, "w");
    if(fp && temp) {
        while(fgets(line, sizeof(line), fp)) {
            if(strncmp(line, "Date:", 5) == 0) {
                if(strcmp(date, strtok(line+5, "\n")) == 0) {
                    flag = 1;
                }
                else {
                    fprintf(temp, "%s", line);
                }
            }
            else {
                fprintf(temp, "%s", line);
            }
        }
        if(flag == 1) {
            printf("%s entry deleted successfully.\n", date);
            remove(fileName);
            rename(tempFile, fileName);
        }
        else {
            printf("%s entry not found.\n", date);
            remove(tempFile);
        }
        fclose(fp);
        fclose(temp);
    }
    else {
        printf("Cannot find file.\n");
    }
    displayMenu();
}

// Search an existing diary entry
void search() {
    FILE *fp;
    char fileName[MAX_FILE_LENGTH], line[MAX_ENTRY_LENGTH], date[20], tempFile[] = "temp.txt";
    int flag = 0;
    printf("Enter the date you want to search (dd-mm-yyyy):\n");
    scanf("%s", date);
    fp = fopen(tempFile, "w");
    if(fp) {
        fclose(fp);
        system("dir /b *.txt > temp.txt");
        fp = fopen(tempFile, "r");
        printf("Search results for %s:\n", date);
        while(fgets(line, sizeof(line), fp)) {
            strtok(line, "\n");
            if(strncmp(line, date, 10) == 0) {
                printf("%s\n", line);
                flag = 1;
            }
        }
        if(flag == 0) {
            printf("No results found for %s.\n", date);
        }
        fclose(fp);
        remove(tempFile);
    }
    else {
        printf("Cannot perform search.\n");
    }
    displayMenu();
}

// Quit the program
void quit() {
    printf("Thank you for using the Digital Diary. Goodbye!\n");
}