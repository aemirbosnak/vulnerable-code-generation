//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* QoS variables */
int service_rate = 0;
int service_cnt = 0, service_sum = 0;
int arrival_cnt = 0, arrival_sum = 0;
double response_time = 0;

/* Function to calculate QoS metrics */
void calculate_qos(int arrival_time, int service_time)
{
    arrival_cnt++;
    arrival_sum += arrival_time;

    /* If there is a service taking place */
    if (service_time > 0){
        service_cnt++;
        service_sum += service_time;

        /* Calculate response time */
        response_time += (double)(service_time + arrival_time - service_rate*service_cnt)/service_cnt;
    }
}

/* Main function */
int main()
{
    /* Prompt user for service rate */
    printf("Please enter service rate (in seconds): ");
    scanf("%d",&service_rate);

    /* Keep taking inputs until user says stop */
    int arrival_time, service_time;
    while(1){
        printf("Enter arrival time and service time (or enter -1 to stop): ");
        scanf("%d%d",&arrival_time,&service_time);

        /* If user says stop */
        if(arrival_time == -1 || service_time == -1)
            break;

        /* Calculate QoS metrics */
        calculate_qos(arrival_time, service_time);
    }

    /* Print QoS metrics */
    printf("Arrival Rate: %f\n", (double)arrival_cnt/arrival_sum);
    printf("Service Rate: %f\n", (double)service_cnt/service_sum);
    printf("Response Time: %f\n", response_time);

    return 0;
}