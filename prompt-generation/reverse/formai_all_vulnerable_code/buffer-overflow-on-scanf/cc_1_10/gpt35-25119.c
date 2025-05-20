//FormAI DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char* encrypt(char* str, int key);
char* decrypt(char* str, int key);

int main(){
    int choice, key;
    char filename[20];
    printf("Welcome to Personal Digital Diary\n");

    while(1){
        printf("\nEnter any one of the following commands:\n");
        printf("1. Create new diary\n");
        printf("2. Open an existing diary\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            FILE* fp;
            char date[12], entry[200], enc_entry[400];

            printf("\nEnter a filename to save diary: ");
            scanf("%s", filename);
            strcat(filename, ".txt");

            fp = fopen(filename, "w");
            if(fp == NULL){
                printf("\nError creating diary!\n");
                continue;
            }

            printf("\nDiary is open for the day: %s\n", __DATE__);
            printf("\nYou can start your entry now. Use [END] to finish.\n");

            while(1){
                getchar();
                printf("> ");
                fgets(entry, 200, stdin);
                if(strncmp(entry, "[END]", 5) == 0){
                    break;
                }
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                sprintf(date, "[%d-%d-%d %d:%d:%d] ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
                strcat(date, entry);
                strcpy(enc_entry, encrypt(date, key));
                fputs(enc_entry, fp);
            }

            printf("\nDiary entry saved successfully!\n");
            fclose(fp);
        }
        else if(choice == 2){
            FILE* fp;
            char entry[400];

            printf("\nEnter filename to open diary: ");
            scanf("%s", filename);
            strcat(filename, ".txt");

            fp = fopen(filename, "r");
            if(fp == NULL){
                printf("\nError opening diary!\n");
                continue;
            }

            printf("\nContents of diary '%s': \n\n", filename);
            while(fgets(entry, 400, fp) != NULL){
                printf("%s\n", decrypt(entry, key));
            }
            fclose(fp);
        }
        else if(choice == 3){
            printf("\nExiting Personal Digital Diary...Goodbye!\n");
            break;
        }
        else{
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

char* encrypt(char* str, int key){
    char* enc = (char*) malloc(sizeof(char)*strlen(str));
    int i;
    for(i=0; i<strlen(str); i++){
        enc[i] = (char)((int)str[i] + key);
    }
    enc[i] = '\0';
    return enc;
}

char* decrypt(char* str, int key){
    char* dec = (char*) malloc(sizeof(char)*strlen(str));
    int i;
    for(i=0; i<strlen(str); i++){
        dec[i] = (char)((int)str[i] - key);
    }
    dec[i] = '\0';
    return dec;
}