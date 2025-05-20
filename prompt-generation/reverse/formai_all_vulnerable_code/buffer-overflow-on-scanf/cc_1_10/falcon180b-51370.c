//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

struct car{
    int id;
    int speed;
    int lane;
    int position;
    int waiting_time;
    int waiting_lane;
    int waiting_position;
};

void init_car(struct car *car, int id, int speed, int lane, int position){
    car->id = id;
    car->speed = speed;
    car->lane = lane;
    car->position = position;
    car->waiting_time = 0;
    car->waiting_lane = -1;
    car->waiting_position = -1;
}

void print_car(struct car car){
    printf("Car %d is at position %d in lane %d with speed %d\n", car.id, car.position, car.lane, car.speed);
}

void move_car(struct car *car){
    car->position += car->speed;
    if(car->position >= 100){
        car->position = 0;
    }
}

int check_collision(struct car *car1, struct car *car2){
    if((car1->lane == car2->lane) && (car1->position >= car2->position) && (car1->position <= car2->position + car2->speed)){
        return 1;
    }
    return 0;
}

void simulate_traffic(struct car *cars, int num_cars){
    int i, j, k;
    for(i=0; i<num_cars; i++){
        if(cars[i].waiting_time > 0){
            cars[i].waiting_time--;
        }
        else{
            for(j=0; j<num_cars; j++){
                if(j == i){
                    continue;
                }
                if(check_collision(&cars[i], &cars[j])){
                    cars[i].waiting_time = 3;
                    cars[i].waiting_lane = cars[j].lane;
                    cars[i].waiting_position = cars[j].position + cars[j].speed;
                }
            }
            move_car(&cars[i]);
        }
    }
}

void main(){
    int num_cars, i;
    struct car cars[MAX];
    srand(time(0));
    printf("Enter number of cars (max %d): ", MAX);
    scanf("%d", &num_cars);
    for(i=0; i<num_cars; i++){
        init_car(&cars[i], i, rand()%10+1, rand()%3, 0);
    }
    while(1){
        system("clear");
        for(i=0; i<num_cars; i++){
            print_car(cars[i]);
        }
        simulate_traffic(cars, num_cars);
        usleep(100000);
    }
}