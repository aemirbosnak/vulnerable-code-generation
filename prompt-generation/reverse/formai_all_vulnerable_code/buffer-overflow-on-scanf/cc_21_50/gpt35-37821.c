//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int num_floors, num_elevators, num_people, elevator_capacity, i, j, k, temp, counter=0;
    int **elevator_state, *all_floors, *all_people, *arrival_time, *destination, *elevator_current_floor, *elevator_status, *elevator_pickup_floor;
    int flag=1, time_cnt=0, elevator_time=0, num_executed=0, total_waiting_time=0, maximum_waiting_time=0;
    float avg_waiting_time;

    srand(time(NULL));

    printf("\n====ELEVATOR SIMULATOR PROGRAM IN PARANOID STYLE====\n");

    // Taking input from the user
    printf("\nEnter the total number of floors in building: ");
    scanf("%d", &num_floors);

    printf("\nEnter the total number of elevators in the building: ");
    scanf("%d", &num_elevators);

    printf("\nEnter the capacity of each elevator: ");
    scanf("%d", &elevator_capacity);

    printf("\nEnter the total number of people in the building: ");
    scanf("%d", &num_people);

    // Initializing arrays
    all_people=(int*)malloc(num_people*sizeof(int));
    all_floors=(int*)malloc(num_floors*sizeof(int));
    arrival_time=(int*)malloc(num_people*sizeof(int));
    destination=(int*)malloc(num_people*sizeof(int));
    elevator_current_floor=(int*)malloc(num_elevators*sizeof(int));
    elevator_status=(int*)malloc(num_elevators*sizeof(int));
    elevator_pickup_floor=(int*)malloc(num_elevators*sizeof(int));
    elevator_state=(int**)malloc(num_elevators*sizeof(int*));
    for(i=0;i<num_elevators;i++)
        elevator_state[i]=(int*)malloc(elevator_capacity*sizeof(int));

    // Initializing all_floors array
    for(i=0;i<num_floors;i++)
        all_floors[i]=i+1;

    // Initializing all_people array
    for(i=0;i<num_people;i++)
        all_people[i]=i+1;

    // Setting initial elevator states
    for(i=0;i<num_elevators;i++){
        elevator_current_floor[i]=1;
        elevator_status[i]=0;
        elevator_pickup_floor[i]=1;
        for(j=0;j<elevator_capacity;j++)
            elevator_state[i][j]=-1;
    }

    // Generating arrival time and destination of the people
    for(i=0;i<num_people;i++){
        arrival_time[i]=rand()%100;
        destination[i]=rand()%(num_floors-1)+2;
    }

    // Starting elevator simulation
    while(num_executed<num_people){

        time_cnt++;

        // Adding people to the elevator if they arrive at this time
        for(i=0;i<num_people;i++){
            if(arrival_time[i]==time_cnt){
                for(j=0;j<num_elevators;j++){
                    if(elevator_status[j]==0 && elevator_current_floor[j]==1){
                        for(k=0;k<elevator_capacity;k++){
                            if(elevator_state[j][k]==-1){
                                elevator_state[j][k]=all_people[i];
                                num_executed++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Moving elevators
        for(i=0;i<num_elevators;i++){
            for(j=0;j<elevator_capacity;j++){
                if(elevator_state[i][j]==-1)
                    continue;
                else if(elevator_state[i][j]==destination[elevator_state[i][j]-1]){
                    elevator_status[i]=-1;
                    elevator_pickup_floor[i]=-1;
                    elevator_state[i][j]=-1;
                    counter++;
                    if(counter==elevator_capacity)
                        counter=0;
                }
                else{
                    elevator_status[i]=1;
                    if(elevator_current_floor[i]<elevator_pickup_floor[i]){
                        elevator_current_floor[i]++;
                        elevator_time++;
                    }
                    else if(elevator_current_floor[i]>elevator_pickup_floor[i]){
                        elevator_current_floor[i]--;
                        elevator_time++;
                    }
                    else if(elevator_current_floor[i]==elevator_pickup_floor[i]){
                        if(destination[elevator_state[i][j]-1]>elevator_current_floor[i]){
                            elevator_current_floor[i]++;
                            elevator_time++;
                        }
                        else if(destination[elevator_state[i][j]-1]<elevator_current_floor[i]){
                            elevator_current_floor[i]--;
                            elevator_time++;
                        }
                        else{
                            elevator_pickup_floor[i]=-1;
                            elevator_time=0;
                        }
                    }
                }
            }
        }

        // Counting waiting time of remaining people on the floor
        for(i=2;i<=num_floors;i++){
            temp=0;
            for(j=0;j<num_people;j++){
                if(all_people[j]==-1 || i!=arrival_time[j] || destination[j]-1<i)
                    continue;
                else{
                    temp=1;
                    total_waiting_time++;
                    maximum_waiting_time++;
                }
            }
            if(temp==0)
                maximum_waiting_time=0;
        }

        // Adding more paranoia to the simulator by checking time elapsed and elevator movement
        if(time_cnt%50==0){
            if(flag==1){
                printf("\nELEVATOR MOVEMENT OBSERVED FOR MORE THAN 50 TIME UNITS. SYSTEM IN LOCKDOWN MODE.\n");
                printf("\nPLEASE CLEAR THE AREA AND EVACUATE THE BUILDING IMMEDIATELY.\n");
                flag=0;
            }
        }
        if(elevator_time>=20){
            printf("\nELEVATOR STOPPED MOVING FOR 20 TIME UNITS. SYSTEM IN ALERT MODE.\n");
            elevator_time=0;
        }
        if(maximum_waiting_time>=30){
            printf("\nSOME PEOPLE HAVE BEEN WAITING FOR MORE THAN 30 TIME UNITS. SYSTEM IN PARANOIA MODE.\n");
            maximum_waiting_time=0;
        }

    }

    // Calculating average waiting time
    avg_waiting_time=((float)total_waiting_time)/((float)num_people);

    // Printing simulation results
    printf("\nELEVATOR SIMULATION COMPLETE.\n");
    printf("\nTotal Time Elapsed: %d", time_cnt);
    printf("\nTotal Number of People: %d", num_people);
    printf("\nTotal Number of Elevators: %d", num_elevators);
    printf("\nMaximum Waiting Time of a Person: %d", maximum_waiting_time);
    printf("\nAverage Waiting Time of a Person: %.2f", avg_waiting_time);

    return 0;
}