//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h> 

struct Entry { 
    char title[50]; 
    char date[20]; 
    char content[500]; 
};

void writeEntry(struct Entry entry){ 
    FILE *fp = fopen("digital_diary.txt", "a"); 
    if (fp == NULL){ 
        printf("File not found!\n"); 
        return; 
    } 
    fprintf(fp, "%s\n%s\n%s\n\n", entry.title, entry.date, entry.content); 
    fclose(fp); 
    printf("Entry added successfully!\n"); 
}

void readEntry(){ 
    FILE *fp = fopen("digital_diary.txt", "r"); 
    if (fp == NULL){ 
        printf("File not found!\n"); 
        return; 
    } 
    char c = fgetc(fp); 
    while (c != EOF){ 
        printf("%c", c); 
        c = fgetc(fp); 
    } 
    fclose(fp); 
}

int main(){ 
    printf("Welcome to the digital diary!\n\n"); 
    printf("Menu:\n"); 
    printf("1. Write an entry\n"); 
    printf("2. Read previous entries\n"); 
    printf("3. Exit\n"); 
    int choice; 
    while (1){ 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice){ 
            case 1: { 
                struct Entry entry; 
                printf("Enter title of entry: "); 
                scanf("%s", entry.title); 
                printf("Enter date of entry: "); 
                scanf("%s", entry.date); 
                printf("Enter content of entry: "); 
                scanf(" %[^\n]s", entry.content); 
                writeEntry(entry); 
                break; 
            } 
            case 2: { 
                printf("\n"); 
                readEntry(); 
                printf("\n"); 
                break; 
            } 
            case 3: { 
                printf("Goodbye!\n"); 
                return 0; 
            } 
            default: printf("Invalid choice!\n"); 
        } 
    } 
}