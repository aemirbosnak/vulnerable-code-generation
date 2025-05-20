//FormAI DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <string.h>

/* Function to get the date in the format of dd/mm/yyyy */
void getDateString(char *dateString) {
    char day[3], month[3], year[5];
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%2s/%2s/%4s", day, month, year);

    /* Concatenate the day, month, and year to form the date string */
    strcpy(dateString, day);
    strcat(dateString, "/");
    strcat(dateString, month);
    strcat(dateString, "/");
    strcat(dateString, year);
}

/* Function to get the content for the diary entry */
void getContent(char *content) {
    printf("Enter your entry: \n");
    scanf(" %[^\n]s", content);
}

int main() {
    char fileName[50], dateString[11], content[1000], buffer[3000];
    FILE *fp;

    /* Get the file name for the diary entry */
    printf("Enter the file name: ");
    scanf("%s", fileName);

    /* Get the date for the diary entry */
    getDateString(dateString);

    /* Get the content for the diary entry */
    getContent(content);

    /* Open the file for appending */
    fp = fopen(fileName, "a");

    /* Append the date and content to the file */
    sprintf(buffer, "\nDate: %s\n%s\n", dateString, content);
    fprintf(fp, buffer);

    /* Close the file */
    fclose(fp);

    printf("\nYour diary entry has been saved!\n");
    return 0;
}