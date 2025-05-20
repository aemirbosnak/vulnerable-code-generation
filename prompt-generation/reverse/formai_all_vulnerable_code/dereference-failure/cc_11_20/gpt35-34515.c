//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
/* Ephemeral System Event Logger */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOGS 100

int main()
{
    int i, option, count = 0;
    char logs[MAX_LOGS][100];
    
    system("clear");

    printf("Ephemeral System Event Logger\n\n");

    do {
        printf("1. View Logs\n2. Add Log\n3. Delete Log\n4. Clear All Logs\n5. Exit\n\nOption: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                system("clear");
                printf("Log Count: %d\n\n", count);
                
                if(count == 0) {
                    printf("No logs found!\n\n");
                } else {
                    for(i = 0; i < count; i++) {
                        printf("%d. %s\n", i+1, logs[i]);
                    }
                    printf("\n");
                }
                
                break;

            case 2:
                system("clear");
                
                if(count == MAX_LOGS) {
                    printf("Error: Maximum log count reached!\n\n");
                } else {
                    char new_log[100];
                    printf("Add Log: ");
                    scanf(" %[^\n]", new_log);
                    
                    time_t t = time(NULL);
                    struct tm *tm = localtime(&t);
                    char date[20];
                    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d", 
                            tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
                            tm->tm_hour, tm->tm_min, tm->tm_sec);

                    sprintf(logs[count], "[%s] %s", date, new_log);
                    printf("Log added successfully!\n\n");
                    count++;
                }
                
                break;

            case 3:
                system("clear");
                printf("Log Count: %d\n\n", count);
                
                if(count == 0) {
                    printf("No logs found!\n\n");
                } else {
                    int log_num;
                    printf("Enter log number to delete: ");
                    scanf("%d", &log_num);

                    if(log_num < 1 || log_num > count) {
                        printf("Error: Invalid log number!\n\n");
                    } else {
                        for(i = log_num - 1; i < count - 1; i++) {
                            strcpy(logs[i], logs[i+1]);
                        }
                        count--;
                        printf("Log deleted successfully!\n\n");
                    }
                }
                
                break;

            case 4:
                system("clear");
                printf("Are you sure you want to clear all logs? [y/N]: ");
                
                char clear_confirm[2];
                scanf(" %[^\n]", clear_confirm);

                if(strcmp(clear_confirm, "y") == 0 || strcmp(clear_confirm, "Y") == 0) {
                    count = 0;
                    printf("All logs cleared!\n\n");
                } else {
                    printf("Clear aborted!\n\n");
                }
                
                break;

            case 5:
                system("clear");
                printf("Exiting...\n\n");
                break;

            default:
                system("clear");
                printf("Error: Invalid option!\n\n");
        }

    } while(option != 5);

    return 0;
}