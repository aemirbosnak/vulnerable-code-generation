//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int x;
    int y;
}point;

void create_road(int **road, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            road[i][j] = 0;
        }
    }
}

void create_car(point *car){
    car->x = rand()%100;
    car->y = rand()%100;
}

void move_car(int **road, point *car, int speed){
    car->x += speed;
    car->y += speed;

    if(car->x >= road[0][0] || car->y >= road[0][0] || car->x < 0 || car->y < 0){
        car->x = rand()%100;
        car->y = rand()%100;
    }
}

void draw_road(int **road, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(road[i][j] == 1){
                printf("X ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void draw_car(point car){
    printf("O");
}

int main(){
    srand(time(0));

    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **road = (int **)malloc(rows*sizeof(int *));
    for(int i=0; i<rows; i++){
        road[i] = (int *)malloc(cols*sizeof(int));
    }

    create_road(road, rows, cols);

    int num_of_cars = 10;
    point *cars = (point *)malloc(num_of_cars*sizeof(point));

    for(int i=0; i<num_of_cars; i++){
        create_car(&cars[i]);
    }

    while(1){
        system("clear");
        draw_road(road, rows, cols);

        for(int i=0; i<num_of_cars; i++){
            move_car(road, &cars[i], 1);
            draw_car(cars[i]);
        }

        usleep(100000);
    }

    for(int i=0; i<rows; i++){
        free(road[i]);
    }
    free(road);
    free(cars);

    return 0;
}