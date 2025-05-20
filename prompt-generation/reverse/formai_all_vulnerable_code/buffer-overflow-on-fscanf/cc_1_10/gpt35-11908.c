//FormAI DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void diary();
void read_entry();
void search_entry();
void delete_entry();

FILE *fp;
char date[16], entry[256], c;
int found = 0;

int main(){
    menu();
    return 0;
}

void menu(){
    int choice;
    printf("Menu:\n");
    printf("1. Write to diary\n2. Read diary entry\n3. Search diary entry\n4. Delete entry\n5. Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            diary();
            break;
        case 2:
            read_entry();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            delete_entry();         
            break;      
        case 5:
            printf("Exiting...\n");         
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    menu();
}

void diary(){
    printf("Enter today's date (dd/mm/yyyy):\n");
    scanf("%s", date);

    printf("Enter your diary entry:\n");
    scanf("%c", &c); // To clear the input buffer
    fgets(entry, 256, stdin);

    fp = fopen("diary.txt", "a");
    fprintf(fp, "%s,%s", date, entry);
    fclose(fp);

    printf("Entry successfully added to diary.\n");
}

void read_entry(){
    char search[16];
    found = 0;

    printf("Enter the date of the diary entry you would like to read (dd/mm/yyyy):\n");
    scanf("%s", search);

    fp = fopen("diary.txt", "r");
    while(fscanf(fp, "%[^,],%[^\n]\n", date, entry) != EOF){
        if(strcmp(date, search) == 0){
            printf("Date: %s\nEntry: %s\n", date, entry);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Entry not found.\n");
    fclose(fp);
}

void search_entry(){
    char search[256];
    found = 0;

    printf("Enter the keyword you would like to search:\n");
    scanf("%c", &c); // To clear the input buffer
    fgets(search, 256, stdin);

    fp = fopen("diary.txt", "r");
    while(fscanf(fp, "%[^,],%[^\n]\n", date, entry) != EOF){
        if(strstr(entry, search) != NULL){
            printf("Date: %s\nEntry: %s\n", date, entry);
            found = 1;
        }
    }
    if(found == 0)
        printf("Entry not found.\n");
    fclose(fp);
}

void delete_entry(){
    char search[16], temp[256];
    found = 0;

    printf("Enter the date of the diary entry you would like to delete (dd/mm/yyyy):\n");
    scanf("%s", search);

    fp = fopen("diary.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");
    while(fscanf(fp, "%[^,],%[^\n]\n", date, entry) != EOF){
        if(strcmp(date, search) == 0){
            found = 1;
            continue;
        }
        fprintf(temp_file, "%s,%s", date, entry);
    }

    fclose(fp);
    fclose(temp_file);

    if(found == 0){
        printf("Entry not found.\n");
        remove("temp.txt");
    }
    else{
        fp = fopen("diary.txt", "w");
        temp_file = fopen("temp.txt", "r");

        while(fscanf(temp_file, "%[^,],%[^\n]\n", date, entry) != EOF){
            fprintf(fp, "%s,%s", date, entry);
        }

        fclose(fp);
        fclose(temp_file);
        remove("temp.txt");
        printf("Entry successfully deleted from diary.\n");
    }
}