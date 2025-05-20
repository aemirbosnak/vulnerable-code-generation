//FormAI DATASET v1.0 Category: Browser Plugin ; Style: statistical
/* Statistical Plugin for C Browser */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate mean */
float mean(int arr[], int n) {
    int i;
    float sum = 0;
    for(i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

/* Function to calculate median */
float median(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    if(n%2 == 0) {
        return (float)(arr[(n/2)-1] + arr[n/2])/2;
    } else {
        return (float)arr[n/2];
    }
}

/* Function to calculate mode */
int mode(int arr[], int n) {
    int i, j, max_count = 0, mode = 0, count;
    for(i = 0; i < n; i++) {
        count = 0;
        for(j = 0; j < n; j++) {
            if(arr[j] == arr[i]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    return mode;
}

/* Function to display statistical data in browser */
void display_statistics(char* message) {
    // Convert message to array of integers
    int arr[50], i = 0;
    char* token = strtok(message, ",");
    while(token != NULL) {
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }
    int n = i;
    float mean_res = mean(arr, n);
    float median_res = median(arr, n);
    int mode_res = mode(arr, n);

    printf("<html><body>");
    printf("<h3>Statistical Data</h3>");
    printf("<p>Mean: %.2f</p>", mean_res);
    printf("<p>Median: %.2f</p>", median_res);
    printf("<p>Mode: %d</p>", mode_res);
    printf("</body></html>");
}

/* Main function */
int main() {
    char message[500];
    printf("Enter integers separated by comma: ");
    fgets(message, 500, stdin);
    display_statistics(message);
    return 0;
}