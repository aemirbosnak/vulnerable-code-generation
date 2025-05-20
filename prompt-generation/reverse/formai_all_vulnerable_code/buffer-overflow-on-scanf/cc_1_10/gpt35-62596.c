//FormAI DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Define the structure for Diary */
struct Diary {
    char date[10];
    char content[1000];
};

/* Function to get the current date */
char* getDate() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char *date = malloc(10*sizeof(char));
    sprintf(date,"%02d/%02d/%d",t->tm_mday,t->tm_mon+1,t->tm_year+1900);
    return date;
}

/* Function to add entry to the diary */
void addEntry() {
    FILE *fp;
    struct Diary d;
    char ch;
    printf("Enter today's date (dd/mm/yyyy): ");
    scanf("%s",d.date);
    getchar();
    printf("Enter content: ");
    fgets(d.content,sizeof(d.content),stdin);
    fp = fopen("diary.txt","a");
    fprintf(fp,"%s\n%s\n",d.date,d.content);
    fclose(fp);
    printf("Entry added successfully!\n");
}

/* Function to display entries */
void viewEntries() {
    FILE *fp;
    struct Diary d;
    char ch;
    fp = fopen("diary.txt","r");
    while(!feof(fp)) {
        fgets(d.date,sizeof(d.date),fp);
        fgets(d.content,sizeof(d.content),fp);
        if(strlen(d.date)>1) {
            printf("Date: %sContent: %s\n",d.date,d.content);
        }
    }
    fclose(fp);
}

/* Function to search for entries */
void searchEntries() {
    FILE *fp;
    struct Diary d;
    char ch;
    char searchDate[10];
    printf("Enter date to search (dd/mm/yyyy): ");
    scanf("%s",searchDate);
    fp = fopen("diary.txt","r");
    while(!feof(fp)) {
        fgets(d.date,sizeof(d.date),fp);
        fgets(d.content,sizeof(d.content),fp);
        if(strcmp(d.date,searchDate)==0) {
            printf("Date: %sContent: %s\n",d.date,d.content);
        }
    }
    fclose(fp);
}

/* Main function */
int main() {
    int ch;
    printf("Welcome to your Digital Diary!\n");
    printf("1. Add Entry\n2. View Entries\n3. Search Entries\n4. Exit\n");
    while(1) {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                printf("Thank you for using Digital Diary!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}