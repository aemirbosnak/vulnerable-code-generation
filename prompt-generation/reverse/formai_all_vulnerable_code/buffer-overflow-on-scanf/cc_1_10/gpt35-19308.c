//FormAI DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

int main() 
{ 
    FILE *fptr; 
    char filename[100], entry[500], date[20]; 
    time_t now; 
    struct tm *currentTime; 
 
    // Getting the current date and time
    now = time(NULL); 

    // Storing the local time
    currentTime = localtime(&now); 

    // Formatting the date and time
    strftime(date, 20, "%Y-%m-%d %H:%M:%S", currentTime); 

    // Asking user for file name 
    printf("Enter the name of the file: "); 
    scanf("%s", filename); 

    // Opening file in write mode 
    fptr = fopen(filename, "w"); 

    // Checking if file opened successfully 
    if (fptr == NULL) 
    { 
        printf("File could not be opened.\n"); 
        exit(1); 
    } 

    // Asking user for entry 
    printf("Enter your entry for today's date: "); 
    scanf(" %[^\n]", entry); 

    // Writing date and entry to file 
    fprintf(fptr, "Date: %s\n", date); 
    fprintf(fptr, "Entry: %s\n", entry); 

    // Closing file 
    fclose(fptr); 

    // Displaying success message 
    printf("Your entry has been saved to '%s'.\n", filename); 

    return 0; 
}