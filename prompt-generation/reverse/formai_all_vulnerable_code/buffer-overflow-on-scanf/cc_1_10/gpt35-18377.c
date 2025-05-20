//FormAI DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    //Declare variables
    char name[20], note[1000], option, end, entry_date[20];
    int entry_no = 0;
    time_t current_time;
    struct tm *local_time;

    //Get user's name and greetings
    printf("Welcome to your Digital Diary!\n\n");
    printf("Please enter your name: ");
    fgets(name, 20, stdin);
    printf("\nHello %s! How can I assist you today?\n\n", name);

    //Loop through diary entries and display options
    do {
        printf("Please choose an option:\n");
        printf("1. Add a new diary entry\n");
        printf("2. View previous diary entries\n");
        printf("3. Quit\n");
        scanf(" %c", &option);

        //Add a new diary entry
        if (option == '1'){
            printf("\nEnter the entry date (dd/mm/yyyy): ");
            scanf("%s", entry_date);
            printf("\nPlease enter your note for the day:\n");
            fflush(stdin);
            fgets(note, 1000, stdin);
            entry_no++;

            //Save entry to file
            current_time = time(NULL);
            local_time = localtime(&current_time);
            char filename[50];
            sprintf(filename, "%s_%02d%02d%02d%02d%02d.txt", name, local_time->tm_year+1900, local_time->tm_mon+1, local_time->tm_mday, local_time->tm_hour, local_time->tm_min);
            FILE *fptr;
            fptr = fopen(filename, "w");
            fprintf(fptr, "Name: %s\nEntry No: %d\nEntry Date: %s\n\n%s", name, entry_no, entry_date, note);
            fclose(fptr);

            printf("\nEntry saved successfully!\n\n");
        }

        //View previous diary entries
        else if (option == '2') {
            char input_date[20];
            printf("\nEnter the date of the entry you want to view (dd/mm/yyyy): ");
            scanf("%s", input_date);
            char filename[50];
            sprintf(filename, "%s_*.txt", name);
            int count = 0;

            //Loop through all files in directory and display matching entries
            printf("\nPrevious Entries:\n");
            FILE *fptr;
            fptr = fopen(filename, "r");
            while (fptr && !feof(fptr)) {
                char line[1000+1];
                fgets(line, sizeof(line), fptr);

                if (strstr(line, input_date) != NULL){
                    printf("\n%s\n", line);
                    count++;
                }
            }
            fclose(fptr);

            if (count == 0) {
                printf("\nNo entries found for the specified date.\n");
            }
        }

        //Quit program
        else if (option == '3') {
            printf("\nThank you for using Digital Diary. Goodbye!\n");
            return 0;
        }

        //Handle incorrect input
        else {
            printf("\nInvalid input. Please choose a valid option.\n\n");
        }

        //Ask user if they want to continue
        printf("\nDo you want to continue? (y/n)");
        scanf(" %c", &end);
        printf("\n");

    } while (end != 'n');

    printf("\nThank you for using Digital Diary. Goodbye!\n");
    return 0;
}