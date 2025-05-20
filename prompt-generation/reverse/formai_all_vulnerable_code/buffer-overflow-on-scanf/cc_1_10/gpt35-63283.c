//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void displayMenu();
void addEntry(FILE *file);
void viewEntry(FILE *file);
int checkPIN(FILE *file, char *filePIN);
void clearBuffer();

int main(){
    int choice, PINCheck;
    char userPIN[7];

    FILE *file;
    file = fopen("diary.txt", "a+");

    if(file==NULL){
        printf("Error opening file.\n");
        return 0;
    }

    do{
        displayMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter 6-digit PIN to access diary: ");
                scanf("%6s", userPIN);
                PINCheck = checkPIN(file, userPIN);
                if(PINCheck){
                    addEntry(file);
                } else {
                    printf("Incorrect PIN. Access denied.\n");
                }
                break;
            case 2:
                printf("Enter 6-digit PIN to access diary: ");
                scanf("%6s", userPIN);
                PINCheck = checkPIN(file, userPIN);
                if(PINCheck){
                    viewEntry(file);
                } else {
                    printf("Incorrect PIN. Access denied.\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice!=3);

    fclose(file);

    return 0;
}

void displayMenu(){
    printf("\n========== Digital Diary ==========\n");
    printf("1 - Add an entry\n");
    printf("2 - View diary\n");
    printf("3 - Exit\n");
    printf("Enter your choice: ");
}

void addEntry(FILE *file){
    char timeString[20];
    time_t currentTime;

    time(&currentTime);
    strftime(timeString, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

    clearBuffer();

    printf("Enter your entry (max 1000 characters):\n");
    char entry[1000];
    fgets(entry, 1000, stdin);
    entry[strcspn(entry, "\n")] = 0;

    fprintf(file, "[%s] %s\n", timeString, entry);

    printf("Entry added successfully.\n");
}

void viewEntry(FILE *file){
    rewind(file);

    printf("\n========== My Diary ==========\n");

    char entry[1024];
    while(fgets(entry, 1024, file)){
        printf("%s", entry);
    }

    printf("\n");
}

int checkPIN(FILE *file, char *filePIN){
    fseek(file, 0, SEEK_SET);

    char actualPIN[7];
    fgets(actualPIN, 7, file);

    if(strcmp(actualPIN, filePIN)==0){
        return 1;
    } else {
        return 0;
    }
}

void clearBuffer(){
    int c = 0;
    while(c!='\n'&&c!=EOF){
        c = getchar();
    }
}