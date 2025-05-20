//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to store information about the hotel
struct hotel
{
    int room_no;
    char name[30];
    int age;
    char from[50];
    char to[50];
    int days;
    int cost;
};

//Function to add data to the hotel database
void addData(struct hotel *data)
{
    printf("Enter Room No: ");
    scanf("%d", &data->room_no);
    printf("Enter Guest Name: ");
    scanf(" %[^\n]s", data->name);
    printf("Enter Age: ");
    scanf("%d", &data->age);
    printf("Enter Check-in Date: ");
    scanf(" %[^\n]s", data->from);
    printf("Enter Check-out Date: ");
    scanf(" %[^\n]s", data->to);
    printf("Enter No. of Days of Stay: ");
    scanf("%d", &data->days);
    printf("Enter Cost per Day: ");
    scanf("%d", &data->cost);
}

//Function to display the hotel database
void displayData(struct hotel *data)
{
    printf("\n\n----------------------------------\n");
    printf("Room No: %d\n", data->room_no);
    printf("Guest Name: %s\n", data->name);
    printf("Age: %d\n", data->age);
    printf("Check-in Date: %s\n", data->from);
    printf("Check-out Date: %s\n", data->to);
    printf("No. of Days of Stay: %d\n", data->days);
    printf("Total Cost: %d\n", data->cost * data->days);
    printf("----------------------------------\n\n");
}

int main()
{
    int n;  //Variable to store number of rooms in the hotel
    printf("Enter Number of Rooms in the Hotel: ");
    scanf("%d", &n);

    //Dynamically allocate memory for array of structure
    struct hotel *data = (struct hotel*) malloc(n * sizeof(struct hotel));

    //Loop to add data to the hotel database
    int i;
    for(i=0; i<n; i++)
    {
        printf("\n\nData Entry for Room No. %d", i+1);
        addData(&data[i]);
    }

    //Loop to display data from the hotel database
    printf("\n\nData in Hotel Database:\n\n");
    for(i=0; i<n; i++)
    {
        printf("Data for Room No. %d\n\n", i+1);
        displayData(&data[i]);
    }

    //Free dynamically allocated memory
    free(data);

    return 0;
}