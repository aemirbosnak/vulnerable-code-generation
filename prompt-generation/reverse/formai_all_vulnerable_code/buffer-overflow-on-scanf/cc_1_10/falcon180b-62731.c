//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main(void) {
    int i, j;
    int temp_array[100];
    int max_temp = 0;
    int min_temp = 1000;
    int avg_temp = 0;
    int count = 0;
    int threshold = 500;
    char filename[50];
    FILE *fp;
    time_t now = time(0);
    struct tm *tm = localtime(&now);
    char *date = asctime(tm);

    printf("Enter the threshold temperature: ");
    scanf("%d", &threshold);

    printf("Enter the filename to store the data: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    fprintf(fp, "Date: %s\nThreshold: %d\n", date, threshold);

    while (TRUE) {
        printf("Enter the temperature (0 to exit): ");
        scanf("%d", &temp_array[count]);
        if (temp_array[count] == 0) {
            break;
        }
        count++;
        if (count == 100) {
            count = 0;
        }
        if (temp_array[count] > max_temp) {
            max_temp = temp_array[count];
        }
        if (temp_array[count] < min_temp) {
            min_temp = temp_array[count];
        }
        avg_temp += temp_array[count];
    }

    fprintf(fp, "Max temperature: %d\nMin temperature: %d\nAverage temperature: %d\n", max_temp, min_temp, avg_temp);

    fclose(fp);

    return 0;
}