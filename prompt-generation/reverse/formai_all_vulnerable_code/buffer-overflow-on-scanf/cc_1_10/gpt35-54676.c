//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//structure to store the diary entry
struct Diary{
    char date[20];
    char entry[200];
};

//function declarations
void addEntry();
void viewEntries();
void searchEntry();
void encrypt();
void decrypt();

int main(){
    int choice;

    printf("\nWelcome to the Digital Diary!\n");

    do{
        printf("\nWhat would you like to do?\n");
        printf("1) Add Diary Entry\n");
        printf("2) View Diary Entries\n");
        printf("3) Search for Diary Entries\n");
        printf("4) Encrypt Diary Entries\n");
        printf("5) Decrypt Diary Entries\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addEntry();
                break;

            case 2:
                viewEntries();
                break;

            case 3:
                searchEntry();
                break;

            case 4:
                encrypt();
                break;

            case 5:
                decrypt();
                break;

            case 6:
                printf("Exiting Digital Diary!");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid choice.");
        }
    }while(choice!=6);
    return 0;
}

//function to add a new diary entry
void addEntry(){
    FILE *fp;
    struct Diary curr;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    //get current date
    strftime(curr.date, sizeof(curr.date), "%d/%m/%Y", tm);

    fflush(stdin);
    printf("\nEnter your diary entry: ");
    fgets(curr.entry, 200, stdin);

    fp = fopen("diary.dat", "ab");
    if(fp == NULL){
        printf("\nError opening file!");
        return;
    }
    fwrite(&curr, sizeof(curr), 1, fp);
    fclose(fp);

    printf("\nDiary entry added successfully!");
}

//function to view all diary entries
void viewEntries(){
    FILE *fp;
    struct Diary curr;

    fp = fopen("diary.dat", "rb");
    if(fp == NULL){
        printf("\nError opening file!");
        return;
    }

    printf("\nAll Entries:\n");
    while(fread(&curr, sizeof(curr), 1, fp)==1){
        printf("Date: %s\n", curr.date);
        printf("Entry: %s\n", curr.entry);
        printf("\n");
    }
    fclose(fp);
}

//function to search for a specific diary entry
void searchEntry(){
    FILE *fp;
    struct Diary curr;
    char searchDate[20];

    printf("\nEnter the date you want to search (dd/mm/yyyy): ");
    fflush(stdin);
    fgets(searchDate, 20, stdin);

    fp = fopen("diary.dat", "rb");
    if(fp == NULL){
        printf("\nError opening file!");
        return;
    }

    while(fread(&curr, sizeof(curr), 1, fp)==1){
        if(strcmp(curr.date, searchDate)==0){
            printf("\nDiary Entry Found:\n");
            printf("Date: %s\n", curr.date);
            printf("Entry: %s\n", curr.entry);
            fclose(fp);
            return;
        }
    }
    printf("\nNo diary entry found for the given date!");
    fclose(fp);
}

//function to encrypt all diary entries
void encrypt(){
    FILE *fpIn, *fpOut;
    struct Diary curr;

    fpIn = fopen("diary.dat", "rb");
    if(fpIn == NULL){
        printf("\nError opening file!");
        return;
    }
    fpOut = fopen("diary_encrypted.dat", "wb");

    if(fpOut == NULL){
        printf("\nError creating file!");
        return;
    }

    while(fread(&curr, sizeof(curr), 1, fpIn)==1){
        for(int i=0;i<strlen(curr.entry);i++){
            curr.entry[i] = curr.entry[i] + 1; //encrypting by shifting each character by 1
        }
        fwrite(&curr, sizeof(curr), 1, fpOut);
    }

    printf("\nDiary entries encrypted successfully!");
    fclose(fpIn);
    fclose(fpOut);
}

//function to decrypt all diary entries
void decrypt(){
    FILE *fpIn, *fpOut;
    struct Diary curr;

    fpIn = fopen("diary_encrypted.dat", "rb");
    if(fpIn == NULL){
        printf("\nError opening file!");
        return;
    }
    fpOut = fopen("diary_decrypted.dat", "wb");

    if(fpOut == NULL){
        printf("\nError creating file!");
        return;
    }

    while(fread(&curr, sizeof(curr), 1, fpIn)==1){
        for(int i=0;i<strlen(curr.entry);i++){
            curr.entry[i] = curr.entry[i] - 1; //decrypting by shifting each character one step back
        }
        fwrite(&curr, sizeof(curr), 1, fpOut);
    }

    printf("\nDiary entries decrypted successfully!");
    fclose(fpIn);
    fclose(fpOut);
}