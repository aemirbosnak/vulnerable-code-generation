//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 //maximum number of characters allowed in a log file

//function signature
void analyze_log_file(char* file_name);

int main(){
    char file_name[MAX_LENGTH];
    
    printf("Enter the name of log file to be analyzed:\n");
    scanf("%s", file_name); //scanning the name of the file from user input
    
    analyze_log_file(file_name); //calling the function to analyze the log file

    return 0;
}

void analyze_log_file(char* file_name){
    FILE* fp;
    char line[MAX_LENGTH]; 
    fp = fopen(file_name, "r"); //opening the log file in read mode

    if(fp == NULL){
        printf("Error: Unable to open file %s", file_name);
        return;
    }

    printf("LOG FILE ANALYSIS REPORT\n\n"); //report heading
    printf("==========================================\n\n"); 

    //iterating through each line of the log file
    while(fgets(line, MAX_LENGTH, fp)!=NULL){
        int comma_count = 0;
        int colon_count = 0;
        char* token;
        char* tokens[MAX_LENGTH];
        token = strtok(line, " "); 

        //tokenizing each line into individual tokens separated by space
        while(token != NULL){
            tokens[comma_count] = token;
            comma_count++;
            token = strtok(NULL, " ");
        }

        //iterating through each token to count the number of colons
        for(int i=0; i<comma_count; i++){
            int len = strlen(tokens[i]);
            for(int j=0; j<len; j++){
                if(tokens[i][j]==':'){
                    colon_count++;
                }
            }
        }

        //if number of colons are greater than 6 then report the line as a possible intrusion attempt
        if(colon_count>6){
            printf("WARNING: Possible Intrusion Attempt detected!\n");
            printf("Details:\n%s", line);
            printf("==========================================\n\n"); 
        }

        //resetting colon_count to 0 for the next line
        colon_count = 0;

    }

    printf("Log File Analysis Completed Successfully"); //reporting successful completion of log file analysis
    fclose(fp); //closing the file
}