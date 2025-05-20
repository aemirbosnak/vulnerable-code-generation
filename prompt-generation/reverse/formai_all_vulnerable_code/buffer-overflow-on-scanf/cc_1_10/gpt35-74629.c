//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Structure to hold the fitness data
struct fitness_data{
    char date[15];
    int steps;
    float distance;
    float time;
};

//Function to add fitness data
void add_fitness_data(struct fitness_data *data){
    printf("Enter the date (yyyymmdd): ");
    scanf("%s", data->date);
    printf("Enter the number of steps taken: ");
    scanf("%d", &data->steps);
    printf("Enter the distance travelled in km: ");
    scanf("%f", &data->distance);
    printf("Enter the duration of the activity in minutes: ");
    scanf("%f", &data->time);
}

//Function to display fitness data
void display_fitness_data(struct fitness_data *data){
    printf("%s\t%d\t%.2f\t%.2f\n", data->date, data->steps, data->distance, data->time);
}

//Function to get total distance travelled
float get_total_distance(struct fitness_data *data, int size){
    float total_distance = 0;
    for(int i = 0; i<size; i++){
        total_distance += data[i].distance;
    }
    return total_distance;
}

//Function to get average steps taken per day
float get_avg_steps(struct fitness_data *data, int size){
    int total_steps = 0;
    for(int i = 0; i<size; i++){
        total_steps += data[i].steps;
    }
    return (float)total_steps/size;
}

//Main function
int main(){
    int choice;
    int size = 0;
    struct fitness_data *data = NULL;

    //Loop for menu-driven program
    do{
        printf("\nFitness Tracker Menu\n");
        printf("1. Add new data\n");
        printf("2. Display all data\n");
        printf("3. Display total distance travelled\n");
        printf("4. Display average steps taken per day\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //Add new data
                if(data == NULL){
                    data = (struct fitness_data*)malloc(sizeof(struct fitness_data));
                }
                else{
                    data = (struct fitness_data*)realloc(data, (size+1)*sizeof(struct fitness_data));
                }
                add_fitness_data(&data[size]);
                size++;
                break;

            case 2:
                //Display all data
                printf("Date\tSteps\tDistance\tTime\n");
                for(int i = 0; i<size; i++){
                    display_fitness_data(&data[i]);
                }
                break;

            case 3:
                //Display total distance travelled
                printf("Total distance travelled: %.2f km\n", get_total_distance(data, size));
                break;

            case 4:
                //Display average steps taken per day
                printf("Average steps taken per day: %.2f\n", get_avg_steps(data, size));
                break;

            case 0:
                //Exit program
                free(data);
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, please try again\n");
        }

    }while(choice != 0);

    return 0;
}