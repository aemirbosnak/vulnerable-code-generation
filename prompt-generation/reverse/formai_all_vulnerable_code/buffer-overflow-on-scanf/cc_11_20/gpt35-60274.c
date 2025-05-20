//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <time.h> 

struct Appointment {  
    char name[100];  
    char date[20];  
    char time[20];  
    char reason[500];  
};  

int main() {  
    int choice, count = 0, i;  
    struct Appointment app[50];  
    char temp[200], searchName[100];  
    time_t t = time(NULL);  
    struct tm tm = *localtime(&t);  
    char currentDate[20], currentTime[20];  
    snprintf(currentDate, sizeof(currentDate), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);  
    snprintf(currentTime, sizeof(currentTime), "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);  
    
    printf("=============================================\n");  
    printf("        Cyberpunk Appointment Scheduler       \n");  
    printf("                      v1.0                    \n");  
    printf("=============================================\n\n");  
    
    do {  
        printf("1. Add Appointment\n");  
        printf("2. Search Appointment\n");  
        printf("3. View All Appointments\n");  
        printf("4. Exit\n");  
        printf("Choice: ");  
        scanf("%d", &choice);  
        
        switch (choice) {  
            case 1:  
                if (count < 50) {  
                    printf("\nEnter Name: ");  
                    fgets(temp, sizeof(temp), stdin);  
                    fgets(app[count].name, sizeof(app[count].name), stdin);  
                    app[count].name[strcspn(app[count].name, "\n")] = 0;  
                    
                    printf("Enter Date (yyyy-mm-dd): ");  
                    scanf("%s", app[count].date);  
                    
                    printf("Enter Time (hh:mm): ");  
                    scanf("%s", app[count].time);  
                    
                    printf("Reason: ");  
                    fgets(temp, sizeof(temp), stdin);  
                    fgets(app[count].reason, sizeof(app[count].reason), stdin);  
                    app[count].reason[strcspn(app[count].reason, "\n")] = 0;  
                    
                    printf("\nAppointment Added Successfully!\n\n");  
                    count++;  
                } else {  
                    printf("\nMaximum Appointments Reached!\n\n");  
                }  
                break;  
              
            case 2:  
                printf("\nEnter Name: ");  
                fgets(temp, sizeof(temp), stdin);  
                fgets(searchName, sizeof(searchName), stdin);  
                searchName[strcspn(searchName, "\n")] = 0;  
                
                for (i = 0; i < count; i++) {  
                    if (strcmp(searchName, app[i].name) == 0) {  
                        printf("\nName: %s", app[i].name);  
                        printf("Date: %s\n", app[i].date);  
                        printf("Time: %s\n", app[i].time);  
                        printf("Reason: %s\n\n", app[i].reason);  
                        break;  
                    }  
                }  
                
                if (i == count) {  
                    printf("\nSorry, Appointment not found.\n\n");  
                }  
                break;  
              
            case 3:  
                printf("\n");  
                for (i = 0; i < count; i++) {  
                    printf("Name: %s", app[i].name);  
                    printf("Date: %s\n", app[i].date);  
                    printf("Time: %s\n", app[i].time);  
                    printf("Reason: %s\n\n", app[i].reason);  
                }  
                break;  
              
            case 4:  
                printf("\nExiting...");  
                break;  
              
            default:  
                printf("\nInvalid Choice! Please Try Again.\n");  
                break;  
        }  
    } while (choice != 4);  
    
    printf("\n");  
    return 0;  
}