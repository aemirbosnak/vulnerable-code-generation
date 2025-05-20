//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

//function to calculate leap year
int isLeapYear(int year){
    if((year%4==0 && year%100!=0) || (year%400==0))
        return 1;
    else
        return 0;
}

//structure to store diary entry
struct DiaryEntry {
    char date[10];
    char entry[1000];
};

//main function
int main(){
    struct DiaryEntry entry; //declare structure variable
    FILE *fp; //declare file pointer
    char choice; //variable to store user's choice
    
    printf("Welcome to your Digital Diary\n");
    
    //menu
    while(1){
        printf("\nChoose an option:\n");
        printf("1. Create new diary entry\n");
        printf("2. View previous diary entry\n");
        printf("3. Exit\n");
        scanf(" %c",&choice);
        
        switch(choice){
            case '1':
                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf(" %[^\n]",entry.date);
                printf("Enter your diary entry:\n");
                scanf(" %[^\n]",entry.entry);
                
                fp = fopen(entry.date,"w"); //open file in write mode
                fprintf(fp,"%s\n%s",entry.date,entry.entry); //write to file
                fclose(fp); //close the file
                printf("\nDiary entry created successfully!\n");
                break;
                
            case '2':
                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf(" %[^\n]",entry.date);
                
                fp = fopen(entry.date,"r"); //open file in read mode
                if(fp==NULL){ //if file does not exist
                    printf("\nDiary entry not found!\n");
                    break;
                }
                else{ //if file exists
                    fscanf(fp,"%[^\n]",entry.date); //read date from file
                    printf("\nDate: %s\n",entry.date);
                    fgetc(fp); //discard newline character
                    fgets(entry.entry,1000,fp); //read entry from file
                    printf("Entry: %s",entry.entry);
                    fclose(fp); //close the file
                }
                break;
                
            case '3':
                printf("\nThanks for using Digital Diary!\n");
                exit(0); //exit the program
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}