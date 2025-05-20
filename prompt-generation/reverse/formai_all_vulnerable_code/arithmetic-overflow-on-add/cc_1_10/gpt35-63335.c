//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Entry{
    char date[11];
    char time[6];
    char content[101];
};

int main(){
    printf("\n*************************************");
    printf("\n*** Welcome to your Digital Diary! ***");
    printf("\n*************************************\n");
    
    int choice;
    do{
        printf("\nWhat would you like to do?\n");
        printf("\n1. Create a new entry\n2. View previous entries\n3. Exit\n");
        printf("\nEnter your choice (1, 2 or 3): ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                struct Entry newEntry;
                
                //Getting current date and time
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                sprintf(newEntry.date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
                sprintf(newEntry.time, "%02d:%02d", tm.tm_hour, tm.tm_min);
                
                //Getting entry content
                printf("\nEnter your entry:\n");
                fflush(stdin);
                fgets(newEntry.content, sizeof(newEntry.content), stdin);
                
                //Saving entry to file
                FILE *fp;
                fp = fopen("diary.txt", "a");
                fprintf(fp, "%s %s - %s\n", newEntry.date, newEntry.time, newEntry.content);
                fclose(fp);
                
                printf("\nEntry successfully saved!\n");
                break;
            }
            case 2:{
                FILE *fp;
                fp = fopen("diary.txt", "r");
                
                if(fp == NULL){
                    printf("\nNo previous entries found!\n");
                    break;
                }
                
                char c;
                while((c = getc(fp)) != EOF){
                    printf("%c", c);
                }
                
                fclose(fp);
                break;
            }
            case 3:
                printf("\nThank you for using Digital Diary! Have a nice day!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }while(choice != 3);
    
    return 0;
}