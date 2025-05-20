//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_time(char *buff);

struct fitness_tracker {
    char date[11];
    float total_calories;
    float total_distance;
    float total_steps;
};

// Function to store data for each day's activity
void add_data(struct fitness_tracker *data) {
    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", data->date);

    printf("Enter total calories burned: ");
    scanf("%f", &data->total_calories);

    printf("Enter total distance covered (km): ");
    scanf("%f", &data->total_distance);

    printf("Enter total steps taken: ");
    scanf("%f", &data->total_steps);
}

// Function to display all data entered so far
void display_data(struct fitness_tracker *data) {
    printf("Displaying all data entered so far:\n");
    printf("Date\t| Total Calories\t| Total Distance\t| Total Steps\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < 7; i++) { // Display data for each day of the week
        printf("%s\t| %.2f\t\t| %.2f km\t\t| %.0f\n", data[i].date, data[i].total_calories, data[i].total_distance, data[i].total_steps);
    }
}

// Function to generate a report of the entire week's activity
void generate_report(struct fitness_tracker *data) {
    printf("Generating weekly report:\n");
    printf("Week\t| Total Calories\t| Total Distance\t| Total Steps\n");
    printf("--------------------------------------------------------------\n");

    float total_calories = 0.0, total_distance = 0.0, total_steps = 0.0;

    for (int i = 0; i < 7; i++) { // Calculate totals for each day of the week
        total_calories += data[i].total_calories;
        total_distance += data[i].total_distance;
        total_steps += data[i].total_steps;
    }

    printf("Week 1\t| %.2f\t\t| %.2f km\t\t| %.0f\n", total_calories, total_distance, total_steps);
}

int main() {
    struct fitness_tracker data[7];

    int choice;

    do {
        printf("\nFITNESS TRACKER MENU\n");
        printf("====================\n");
        printf("1. Add Data\n");
        printf("2. Display Data\n");
        printf("3. Generate Weekly Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_data(&data[get_day_of_week()]);
                break;
            case 2:
                display_data(data);
                break;
            case 3:
                generate_report(data);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid choice (1-4).\n");
        }
    } while (choice != 4);

    return 0;
}

void get_time(char *buff) {
    time_t raw_time;
    struct tm *local_time;

    time(&raw_time);
    local_time = localtime(&raw_time);

    strftime(buff, 10, "%m/%d/%Y", local_time);
}

int get_day_of_week() {
    char buff[10];

    get_time(buff);

    int d, m, y;

    d = (buff[3] - '0') * 10 + (buff[4] - '0');
    m = (buff[0] - '0') * 10 + (buff[1] - '0');
    y = (buff[6] - '0') * 1000 + (buff[7] - '0') * 100 + (buff[8] - '0') * 10 + (buff[9] - '0');

    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    int day = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;

    return day;
}