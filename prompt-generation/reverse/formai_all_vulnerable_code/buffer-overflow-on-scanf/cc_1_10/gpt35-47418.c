//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Declare constants and structures
#define ROW 10
#define COL 10
#define MAX_THREADS 10

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    int f;
    Point p;
} Node;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

Node openList[MAX_THREADS][ROW * COL];
int openListSize[MAX_THREADS] = {0};

int closedList[ROW][COL] = {0};
int start_x, start_y, end_x, end_y, find_optimal = 0, num_threads = 0, optimal_cost = 0;
int map[ROW][COL] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

// Declare functions
void find_path(int thread_id);
int is_valid_move(int x, int y);
int calc_f(int g, int h);
int calc_h(int x, int y);
void print_path();

int main()
{
    printf("Enter starting coordinates (x,y): ");
    scanf("%d,%d", &start_x, &start_y);

    printf("Enter ending coordinates (x,y): ");
    scanf("%d,%d", &end_x, &end_y);

    printf("Enter number of threads (1-10): ");
    scanf("%d", &num_threads);

    find_optimal = 1;

    // Create threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, (void *)find_path, (void *)i);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    print_path();

    return 0;
}

void find_path(int thread_id)
{
    int thread_openList[ROW * COL];
    int thread_openListSize = 0;

    Point start = {start_x, start_y};
    Node start_node = {0, start};
    openList[thread_id][0] = start_node;
    openListSize[thread_id]++;

    while (openListSize[thread_id] > 0 && (!find_optimal || openList[thread_id][0].f <= optimal_cost))
    {
        // Get node with smallest f value from openList
        Node current_node = openList[thread_id][0];
        int current_index = 0;
        for (int i = 1; i < openListSize[thread_id]; i++)
        {
            if (openList[thread_id][i].f < current_node.f)
            {
                current_node = openList[thread_id][i];
                current_index = i;
            }
        }

        // Remove current node from openList and add to closedList
        pthread_mutex_lock(&mutex);
        for (int i = current_index; i < openListSize[thread_id] - 1; i++)
        {
            openList[thread_id][i] = openList[thread_id][i + 1];
        }
        openListSize[thread_id]--;
        closedList[current_node.p.x][current_node.p.y] = 1;
        pthread_mutex_unlock(&mutex);

        // Check if current node is goal
        if (current_node.p.x == end_x && current_node.p.y == end_y)
        {
            printf("Thread %d: Found optimal path with cost %d\n", thread_id, current_node.f);
            find_optimal = 0;
            optimal_cost = current_node.f;
            break;
        }

        // Generate children of current node
        Point children[4] = {{current_node.p.x - 1, current_node.p.y},
                             {current_node.p.x, current_node.p.y - 1},
                             {current_node.p.x + 1, current_node.p.y},
                             {current_node.p.x, current_node.p.y + 1}};

        for (int i = 0; i < 4; i++)
        {
            if (is_valid_move(children[i].x, children[i].y))
            {
                // Calculate g, h, and f values for child node
                int g = current_node.f + 1;
                int h = calc_h(children[i].x, children[i].y);
                int f = calc_f(g, h);

                // Check if child node is already in openList or closedList
                int is_in_openList = 0;
                for (int j = 0; j < openListSize[thread_id]; j++)
                {
                    if (openList[thread_id][j].p.x == children[i].x && openList[thread_id][j].p.y == children[i].y)
                    {
                        is_in_openList = 1;
                        if (openList[thread_id][j].f > f)
                        {
                            openList[thread_id][j].f = f;
                        }
                    }
                }
                if (!is_in_openList && !closedList[children[i].x][children[i].y])
                {
                    // Add child node to openList
                    Node child_node = {f, children[i]};
                    pthread_mutex_lock(&mutex);
                    openList[thread_id][openListSize[thread_id]] = child_node;
                    openListSize[thread_id]++;
                    pthread_mutex_unlock(&mutex);
                }
            }
        }
    }
}

int is_valid_move(int x, int y)
{
    if (x < 0 || x >= ROW || y < 0 || y >= COL)
    {
        return 0;
    }
    return map[x][y] == 0;
}

int calc_f(int g, int h)
{
    return g + h;
}

int calc_h(int x, int y)
{
    return abs(x - end_x) + abs(y - end_y);
}

void print_path()
{
    if (!optimal_cost)
    {
        printf("No path found.\n");
        return;
    }

    printf("Path: \n");
    int x = end_x;
    int y = end_y;
    while (x != start_x || y != start_y)
    {
        int min_f = 9999999;
        for (int i = 0; i < num_threads; i++)
        {
            for (int j = 0; j < openListSize[i]; j++)
            {
                if (openList[i][j].p.x == x && openList[i][j].p.y == y && openList[i][j].f < min_f)
                {
                    min_f = openList[i][j].f;
                }
            }
        }

        printf("(%d,%d)", x, y);
        closedList[x][y] = 2; // mark as part of path
        Point children[4] = {{x - 1, y}, {x, y - 1}, {x + 1, y}, {x, y + 1}};
        for (int i = 0; i < 4; i++)
        {
            int child_x = children[i].x;
            int child_y = children[i].y;
            if (is_valid_move(child_x, child_y) && closedList[child_x][child_y] == 1)
            {
                int g = min_f - calc_h(x, y);
                int f = calc_f(g, calc_h(child_x, child_y));
                Node child_node = {f, {child_x, child_y}};
                int is_in_openList = 0;
                for (int j = 0; j < num_threads; j++)
                {
                    for (int k = 0; k < openListSize[j]; k++)
                    {
                        if (openList[j][k].p.x == child_x && openList[j][k].p.y == child_y)
                        {
                            is_in_openList = 1;
                            if (openList[j][k].f > f)
                            {
                                openList[j][k].f = f;
                            }
                        }
                    }
                }
                if (!is_in_openList)
                {
                    pthread_mutex_lock(&mutex);
                    openList[0][openListSize[0]] = child_node;
                    openListSize[0]++;
                    pthread_mutex_unlock(&mutex);
                    pthread_cond_signal(&cond);
                }
            }
        }

        // Wait for other threads to add child nodes to openList
        pthread_mutex_lock(&mutex);
        while (openListSize[0] == 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);

        // Choose next node with smallest f value
        int current_f = 9999999;
        for (int i = 0; i < openListSize[0]; i++)
        {
            if (openList[0][i].p.x == x && openList[0][i].p.y == y && openList[0][i].f < current_f)
            {
                current_f = openList[0][i].f;
            }
        }

        // Remove next node from openList
        for (int i = 0; i < openListSize[0]; i++)
        {
            if (openList[0][i].p.x == x && openList[0][i].p.y == y && openList[0][i].f == current_f)
            {
                x = openList[0][i].p.x;
                y = openList[0][i].p.y;
                for (int j = i; j < openListSize[0] - 1; j++)
                {
                    openList[0][j] = openList[0][j + 1];
                }
                openListSize[0]--;
                break;
            }
        }
    }
    printf("(%d,%d)\n", start_x, start_y);
}