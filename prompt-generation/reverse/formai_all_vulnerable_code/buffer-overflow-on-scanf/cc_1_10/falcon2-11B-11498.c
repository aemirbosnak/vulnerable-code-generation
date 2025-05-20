//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <time.h>

#define MAX_ANGLE 180
#define MIN_ANGLE -180
#define DISTANCE 200

void print_menu(void);
int set_direction(int angle);
int move_forward(void);
int move_backward(void);
int move_left(void);
int move_right(void);
int turn_left(void);
int turn_right(void);
int turn_up(void);
int turn_down(void);

int main(void)
{
    int angle = 0;
    int distance = 0;

    print_menu();

    while (1)
    {
        printf("\nSelect an option: ");
        scanf("%d", &angle);

        if (angle == 1)
            move_forward();
        else if (angle == 2)
            move_backward();
        else if (angle == 3)
            move_left();
        else if (angle == 4)
            move_right();
        else if (angle == 5)
            turn_left();
        else if (angle == 6)
            turn_right();
        else if (angle == 7)
            turn_up();
        else if (angle == 8)
            turn_down();
        else
            printf("Invalid option selected.\n");
    }

    return 0;
}

void print_menu(void)
{
    printf("\n1. Move forward\n2. Move backward\n3. Move left\n4. Move right\n5. Turn left\n6. Turn right\n7. Turn up\n8. Turn down\n");
}

int set_direction(int angle)
{
    if (angle >= 0 && angle <= 180)
    {
        angle %= 180;
        return angle;
    }
    else
    {
        printf("Invalid angle selected.\n");
        return 0;
    }
}

int move_forward(void)
{
    int distance_travelled = 0;

    while (distance_travelled < DISTANCE)
    {
        distance_travelled += 10;
        printf("Distance travelled: %d\n", distance_travelled);
        sleep(1);
    }

    return 0;
}

int move_backward(void)
{
    int distance_travelled = 0;

    while (distance_travelled < DISTANCE)
    {
        distance_travelled -= 10;
        printf("Distance travelled: %d\n", distance_travelled);
        sleep(1);
    }

    return 0;
}

int move_left(void)
{
    int angle_travelled = 0;

    while (angle_travelled < 180)
    {
        angle_travelled += set_direction(set_direction(angle_travelled) - 90);
        printf("Angle travelled: %d\n", angle_travelled);
        sleep(1);
    }

    return 0;
}

int move_right(void)
{
    int angle_travelled = 0;

    while (angle_travelled < 180)
    {
        angle_travelled += set_direction(set_direction(angle_travelled) + 90);
        printf("Angle travelled: %d\n", angle_travelled);
        sleep(1);
    }

    return 0;
}

int turn_left(void)
{
    int angle_travelled = 0;

    while (angle_travelled < 180)
    {
        angle_travelled += set_direction(set_direction(angle_travelled) - 90);
        printf("Angle travelled: %d\n", angle_travelled);
        sleep(1);
    }

    return 0;
}

int turn_right(void)
{
    int angle_travelled = 0;

    while (angle_travelled < 180)
    {
        angle_travelled += set_direction(set_direction(angle_travelled) + 90);
        printf("Angle travelled: %d\n", angle_travelled);
        sleep(1);
    }

    return 0;
}

int turn_up(void)
{
    int distance_travelled = 0;

    while (distance_travelled < DISTANCE)
    {
        distance_travelled += 10;
        printf("Distance travelled: %d\n", distance_travelled);
        sleep(1);
    }

    return 0;
}

int turn_down(void)
{
    int distance_travelled = 0;

    while (distance_travelled < DISTANCE)
    {
        distance_travelled -= 10;
        printf("Distance travelled: %d\n", distance_travelled);
        sleep(1);
    }

    return 0;
}