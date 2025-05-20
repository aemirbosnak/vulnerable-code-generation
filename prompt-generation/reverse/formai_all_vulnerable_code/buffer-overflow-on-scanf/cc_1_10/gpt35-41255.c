//FormAI DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//function for adding a new entry
void add_entry(char *filename){
    FILE *fp;
    fp = fopen(filename, "a");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    char date[100], content[500];
    printf("Enter the date (YYYY-MM-DD): ");
    fgets(date, sizeof(date), stdin);
    printf("Write your entry:\n");
    fgets(content, sizeof(content), stdin);
    fprintf(fp, "%s %s\n", date, content);
    fclose(fp);
}
//function for viewing diary entries
void view_entries(char *filename){
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    char str[1000];
    while(fgets(str, 1000, fp) != NULL){
        printf("%s", str);
    }
    fclose(fp);
}
//function for clearing the diary
void clear_diary(char *filename){
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(fp);
}
int main(){
    char filename[] = "digital_diary.txt";
    int choice;
    //loop for displaying options
    while(1){
        printf("Welcome to your digital diary!\n");
        printf("Choose an option:\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Clear the diary\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                add_entry(filename);
                break;
            case 2:
                view_entries(filename);
                break;
            case 3:
                clear_diary(filename);
                printf("Diary cleared!\n");
                break;
            case 4:
                printf("Thank you for using the digital diary!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}