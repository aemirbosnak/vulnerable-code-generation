//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

#define NS_GREEN_TIME 10
#define EW_GREEN_TIME 10
#define YELLOW_TIME 3

#define NS_ROAD 1
#define EW_ROAD 2

#define MAX_NS_QUEUE_SIZE 5
#define MAX_EW_QUEUE_SIZE 5

int current_state;
int ns_time_left;
int ew_time_left;
int ns_queue[MAX_NS_QUEUE_SIZE];
int ns_front;
int ns_rear;
int ew_queue[MAX_EW_QUEUE_SIZE];
int ew_front;
int ew_rear;

void init_queue()
{
    ns_front = ns_rear = -1;
    ew_front = ew_rear = -1;
}

bool is_ns_queue_empty()
{
    return ns_front == -1;
}

bool is_ew_queue_empty()
{
    return ew_front == -1;
}

bool is_ns_queue_full()
{
    return (ns_front == 0 && ns_rear == MAX_NS_QUEUE_SIZE - 1) || (ns_rear == ns_front - 1);
}

bool is_ew_queue_full()
{
    return (ew_front == 0 && ew_rear == MAX_EW_QUEUE_SIZE - 1) || (ew_rear == ew_front - 1);
}

void add_to_ns_queue(int car_id)
{
    if (is_ns_queue_full())
    {
        printf("North-South queue is full\n");
        return;
    }

    if (is_ns_queue_empty())
    {
        ns_front = ns_rear = 0;
    }
    else if (ns_rear == MAX_NS_QUEUE_SIZE - 1)
    {
        ns_rear = 0;
    }
    else
    {
        ns_rear++;
    }

    ns_queue[ns_rear] = car_id;
}

void add_to_ew_queue(int car_id)
{
    if (is_ew_queue_full())
    {
        printf("East-West queue is full\n");
        return;
    }

    if (is_ew_queue_empty())
    {
        ew_front = ew_rear = 0;
    }
    else if (ew_rear == MAX_EW_QUEUE_SIZE - 1)
    {
        ew_rear = 0;
    }
    else
    {
        ew_rear++;
    }

    ew_queue[ew_rear] = car_id;
}

int remove_from_ns_queue()
{
    if (is_ns_queue_empty())
    {
        printf("North-South queue is empty\n");
        return -1;
    }

    int car_id = ns_queue[ns_front];

    if (ns_front == ns_rear)
    {
        ns_front = ns_rear = -1;
    }
    else if (ns_front == MAX_NS_QUEUE_SIZE - 1)
    {
        ns_front = 0;
    }
    else
    {
        ns_front++;
    }

    return car_id;
}

int remove_from_ew_queue()
{
    if (is_ew_queue_empty())
    {
        printf("East-West queue is empty\n");
        return -1;
    }

    int car_id = ew_queue[ew_front];

    if (ew_front == ew_rear)
    {
        ew_front = ew_rear = -1;
    }
    else if (ew_front == MAX_EW_QUEUE_SIZE - 1)
    {
        ew_front = 0;
    }
    else
    {
        ew_front++;
    }

    return car_id;
}

int get_queue_length(int road)
{
    if (road == NS_ROAD)
    {
        if (is_ns_queue_empty())
        {
            return 0;
        }

        if (ns_front <= ns_rear)
        {
            return ns_rear - ns_front + 1;
        }
        else
        {
            return MAX_NS_QUEUE_SIZE - ns_front + ns_rear + 1;
        }
    }
    else if (road == EW_ROAD)
    {
        if (is_ew_queue_empty())
        {
            return 0;
        }

        if (ew_front <= ew_rear)
        {
            return ew_rear - ew_front + 1;
        }
        else
        {
            return MAX_EW_QUEUE_SIZE - ew_front + ew_rear + 1;
        }
    }

    return 0;
}

void print_queue_status()
{
    printf("North-South Queue: ");
    for (int i = ns_front; i <= ns_rear; i++)
    {
        printf("%d ", ns_queue[i]);
    }
    printf("\n");

    printf("East-West Queue: ");
    for (int i = ew_front; i <= ew_rear; i++)
    {
        printf("%d ", ew_queue[i]);
    }
    printf("\n");
}

void change_state()
{
    if (current_state == RED)
    {
        current_state = GREEN;

        ns_time_left = NS_GREEN_TIME;
        ew_time_left = 0;
    }
    else if (current_state == GREEN)
    {
        current_state = YELLOW;

        ns_time_left = ew_time_left = YELLOW_TIME;
    }
    else if (current_state == YELLOW)
    {
        current_state = RED;

        ns_time_left = 0;
        ew_time_left = EW_GREEN_TIME;
    }
}

void update_queue()
{
    static int car_id = 1;
    static int ns_counter = 0;
    static int ew_counter = 0;

    if (ns_counter == NS_GREEN_TIME)
    {
        ns_counter = 0;
    }

    if (ew_counter == EW_GREEN_TIME)
    {
        ew_counter = 0;
    }

    if (current_state == GREEN)
    {
        if (ns_counter == 0)
        {
            add_to_ns_queue(car_id++);
        }

        if (ew_counter == 0)
        {
            add_to_ew_queue(car_id++);
        }
    }

    if (ns_counter == NS_GREEN_TIME - 1)
    {
        int car_id = remove_from_ew_queue();
        while (car_id != -1)
        {
            printf("Car %d from East-West road goes through the intersection.\n", car_id);
            car_id = remove_from_ew_queue();
        }
    }

    if (ew_counter == EW_GREEN_TIME - 1)
    {
        int car_id = remove_from_ns_queue();
        while (car_id != -1)
        {
            printf("Car %d from North-South road goes through the intersection.\n", car_id);
            car_id = remove_from_ns_queue();
        }
    }

    if (!is_ns_queue_empty() && ns_time_left == 0)
    {
        printf("Car %d from North-South road is still waiting.\n", ns_queue[ns_front]);
        remove_from_ns_queue();
    }

    if (!is_ew_queue_empty() && ew_time_left == 0)
    {
        printf("Car %d from East-West road is still waiting.\n", ew_queue[ew_front]);
        remove_from_ew_queue();
    }

    ns_counter++;
    ew_counter++;
}

void print_traffic_light_status()
{
    if (current_state == RED)
    {
        printf("North-South traffic light is RED.\n");
        printf("East-West traffic light is GREEN.\n");
    }
    else if (current_state == GREEN)
    {
        printf("North-South traffic light is GREEN.\n");
        printf("East-West traffic light is RED.\n");
    }
    else if (current_state == YELLOW)
    {
        printf("North-South traffic light is YELLOW.\n");
        printf("East-West traffic light is YELLOW.\n");
    }
}

int main()
{
    srand(time(NULL));

    current_state = RED;
    ns_time_left = 0;
    ew_time_left = EW_GREEN_TIME;
    init_queue();

    for (int i = 0; i < 60; i++)
    {
        printf("Time: %d\n", i);
        print_traffic_light_status();
        update_queue();
        print_queue_status();
        change_state();

        ns_time_left--;
        ew_time_left--;
    }

    return 0;
}