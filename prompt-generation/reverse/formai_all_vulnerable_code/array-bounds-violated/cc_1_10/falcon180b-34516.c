//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define QUIT 'q'
#define MAX_SENSORS 16
#define MAX_NAME_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    float temp;
    float min_temp;
    float max_temp;
} sensor_t;

sensor_t sensors[MAX_SENSORS];
int num_sensors = 0;

void add_sensor(char* name) {
    sensors[num_sensors].name[0] = '\0';
    strncpy(sensors[num_sensors].name, name, MAX_NAME_LEN);
    sensors[num_sensors].temp = 0;
    sensors[num_sensors].min_temp = 1000;
    sensors[num_sensors].max_temp = -1000;
    num_sensors++;
}

void remove_sensor(int index) {
    int i;
    for(i=index; i<num_sensors-1; i++) {
        sensors[i] = sensors[i+1];
    }
    num_sensors--;
}

void print_sensors() {
    int i;
    for(i=0; i<num_sensors; i++) {
        printf("%s: %.2f C\n", sensors[i].name, sensors[i].temp);
    }
}

int main() {
    char input[256];
    int choice;
    float temp;
    time_t start_time;

    printf("Welcome to the temperature monitor!\n");

    while(TRUE) {
        printf("\n");
        printf("1. Add sensor\n");
        printf("2. Remove sensor\n");
        printf("3. Print sensors\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter sensor name: ");
                scanf("%s", input);
                add_sensor(input);
                break;
            case 2:
                printf("Enter sensor index to remove: ");
                scanf("%d", &choice);
                remove_sensor(choice);
                break;
            case 3:
                print_sensors();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}