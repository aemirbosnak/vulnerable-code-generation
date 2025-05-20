//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void init();
int read_input();
void schedule();
void init_list();
int random_number(int n);
int get_weight();
void load_luggage();
void unload_luggage();
void print_status();
struct Event {
    int time;
    int event_type;
}events[MAX];
int num_events;
int time_now;
int next_event;
int weight;
int num_luggage;
int loaded_luggage;
int unloaded_luggage;
int main() {
    srand(time(NULL));
    printf("************* AIRPORT BAGGAGE HANDLING SIMULATION **************\n");
    init();
    read_input();
    schedule();
    return 0;
}
void init() {
    num_events = 0;
    time_now = 0; 
    next_event = 0;
    weight = 0;
    num_luggage = 0;
    loaded_luggage = 0;
    unloaded_luggage = 0;
    init_list();
}
int read_input() {
    printf("\nEnter the weight of the luggage: ");
    scanf("%d", &weight);
    printf("\nEnter the number of luggage: ");
    scanf("%d", &num_luggage);
}
void schedule() {
    int event_type;
    int time;
    event_type = 1;
    time = random_number(60);
    events[num_events].event_type = event_type;
    events[num_events].time = time;
    num_events++;
    printf("\nEVENT: Schedule next load at time %d\n", time);

    event_type = 2;
    time = random_number(60);
    events[num_events].event_type = event_type;
    events[num_events].time = time;
    num_events++;
    printf("EVENT: Schedule next unload at time %d\n", time);

    event_type = 3;
    time = random_number(240);
    events[num_events].event_type = event_type;
    events[num_events].time = time;
    num_events++;
    printf("EVENT: Schedule end of simulation at time %d\n", time);

    while(next_event < num_events) {
        time_now = events[next_event].time;
        switch(events[next_event].event_type) {
            case 1:
                load_luggage();
                break;
            case 2:
                unload_luggage();
                break;
            case 3:
                printf("******* END OF SIMULATION ********\n");
                printf("Total Luggage: %d\n", num_luggage);
                printf("Loaded Luggage: %d\n", loaded_luggage);
                printf("Unloaded Luggage: %d\n", unloaded_luggage);
                print_status();
                exit(0);
        }
    next_event++;
    }
}
void init_list() {
    num_events = 0;
    next_event = 0;
}
int random_number(int n) {
    int rand_num = rand()%n+1;
    return time_now+rand_num;
}
int get_weight() {
    return random_number(weight);
}
void load_luggage() {
    int num_load_luggage = random_number(num_luggage);
    int total_weight = get_weight() * num_load_luggage;
    loaded_luggage += num_load_luggage;
    num_luggage -= num_load_luggage;
    printf("\nLOADED %d LUGGAGE WITH TOTAL WEIGHT %d AT TIME %d\n", num_load_luggage, total_weight, time_now);
    events[num_events].event_type = 1;
    events[num_events].time = time_now + random_number(60);
    num_events++;
}
void unload_luggage() {
    if(loaded_luggage > 0) {
        int num_unload_luggage = random_number(loaded_luggage);
        unloaded_luggage += num_unload_luggage;
        loaded_luggage -= num_unload_luggage;
        printf("\nUNLOADED %d LUGGAGE AT TIME %d\n", num_unload_luggage, time_now);
    }
    events[num_events].event_type = 2;
    events[num_events].time = time_now + random_number(60);
    num_events++;
}
void print_status() {
    printf("Number of Luggage in Queue: %d\n", num_luggage);
    printf("Number of Loaded Luggage: %d\n", loaded_luggage);  
    printf("Number of Unloaded Luggage: %d\n", unloaded_luggage);  
}