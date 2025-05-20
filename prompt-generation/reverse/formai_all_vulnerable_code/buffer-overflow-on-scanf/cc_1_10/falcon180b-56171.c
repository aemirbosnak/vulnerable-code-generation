//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct diary{
    char date[20];
    char event[50];
    char feeling[20];
}entry;

void add_entry(struct diary *diary){
    time_t now = time(0);
    struct tm *t = localtime(&now);
    strftime(diary->date, 20, "%d/%m/%Y", t);
    printf("Enter event: ");
    scanf("%s", diary->event);
    printf("Enter feeling: ");
    scanf("%s", diary->feeling);
    printf("%s - %s\n", diary->event, diary->feeling);
}

void view_entries(struct diary *diary){
    printf("Date\t\tEvent\t\tFeeling\n");
    printf("------------------------------\n");
    FILE *file = fopen("diary.txt", "r");
    if(file == NULL){
        printf("No entries found.\n");
        fclose(file);
        return;
    }
    char line[100];
    while(fgets(line, sizeof(line), file)!= NULL){
        sscanf(line, "%s %s %s", diary->date, diary->event, diary->feeling);
        printf("%s\t\t%s\t\t%s\n", diary->date, diary->event, diary->feeling);
    }
    fclose(file);
}

int main(){
    struct diary diary;
    int choice;
    FILE *file = fopen("diary.txt", "a");
    if(file == NULL){
        printf("File not found.\n");
        return 0;
    }
    fprintf(file, "Date\t\tEvent\t\tFeeling\n");
    fprintf(file, "------------------------------\n");
    fclose(file);
    while(1){
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_entry(&diary);
                file = fopen("diary.txt", "a");
                fprintf(file, "%s\t\t%s\t\t%s\n", diary.date, diary.event, diary.feeling);
                fclose(file);
                break;
            case 2:
                view_entries(&diary);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}