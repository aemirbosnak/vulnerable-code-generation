//FormAI DATASET v1.0 Category: Log analysis ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000

int main(){
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    int unique_ips = 0;
    int lines_processed = 0;
    char filename[50];
    char line[MAX_LINE_LENGTH];
    char *ptr;
    char ip[20];

    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if(!file){
        printf("File could not be opened.");
        exit(1);
    }

    while(fgets(line, MAX_LINE_LENGTH, file)){
        lines_processed++;
        ptr = strtok(line, " ");
        strcpy(ip, ptr);
        ptr = strtok(NULL, " ");
        ptr = strtok(NULL, "[]");
        ptr = strtok(NULL, "]\"");
        
        total_requests++;
        if(strcmp(ptr, "200") == 0){
            successful_requests++;
        }else{
            failed_requests++;
        }

        if(lines_processed == 1){
            unique_ips++;
        }else{
            int is_unique = 1;
            rewind(file);
            char check_line[MAX_LINE_LENGTH];
            while(fgets(check_line, MAX_LINE_LENGTH, file)){
                char check_ip[20];
                char *check_ptr;
                check_ptr = strtok(check_line, " ");
                strcpy(check_ip, check_ptr);
                if(strcmp(ip, check_ip) == 0){
                    is_unique = 0;
                    break;
                }
            }
            if(is_unique){
                unique_ips++;
            }
        }
    }

    printf("Total Requests: %d\n", total_requests);
    printf("Successful Requests: %d\n", successful_requests);
    printf("Failed Requests: %d\n", failed_requests);
    printf("Unique IPs: %d\n", unique_ips);

    fclose(file);
    return 0;
}