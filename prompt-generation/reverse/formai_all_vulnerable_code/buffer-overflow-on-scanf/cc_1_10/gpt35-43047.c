//FormAI DATASET v1.0 Category: Log analysis ; Style: systematic
#include<stdio.h>
#include<string.h>

//Function to count the number of lines in the log
int countLines(FILE *fp){
    int count=0;
    char ch;
    while ((ch = fgetc(fp)) != EOF){
        if (ch == '\n'){
            count++;
        }
    }
    rewind(fp);
    return count;
}

//Function to read the log file
void readLog(FILE *fp){
    char line[100];
    while(fgets(line,sizeof(line),fp)){
        printf("%s",line);
    }
    printf("\n");
}

//Function to display number of occurences of a particular string
void searchLog(FILE *fp,char *str){
    char line[100];
    int count=0;
    while(fgets(line,sizeof(line),fp)){
        if(strstr(line,str)){
            count++;
        }
    }
    rewind(fp);
    printf("\nNumber of occurrences of the string '%s': %d\n",str,count);
}

//Function to display failed attempts from ssh logs
void sshLogs(FILE *fp){
    char line[100];
    printf("\nFailed SSH login attempts: \n");
    while(fgets(line,sizeof(line),fp)){
        if(strstr(line,"sshd")){
            if(strstr(line,"Failed password")){
                printf("%s",line);
            }
        }
    }
    rewind(fp);
}

int main(){
    char fileName[50], search[50];
    FILE *fp;
    int choice, numLines;
    printf("Enter the log file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Error opening file");
        return 0;
    }

    printf("1. Display log\n");
    printf("2. Count number of lines\n");
    printf("3. Search for a particular string\n");
    printf("4. Display failed SSH login attempts\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            readLog(fp);
            break;
        case 2:
            numLines = countLines(fp);
            printf("\nNumber of lines: %d\n", numLines);
            break;
        case 3:
            printf("Enter the string to search: ");
            scanf("%s", search);
            searchLog(fp, search);
            break;
        case 4:
            sshLogs(fp);
            break;
        default:
            printf("Invalid choice\n");
    }

    fclose(fp);
    return 0;
}