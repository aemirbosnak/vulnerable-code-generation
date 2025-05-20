//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int q, n, sum = 0;
    printf("Enter the number of queries: ");
    scanf("%d", &q);
    
    while(q--)
    {
        printf("Enter the number of packets and minimum bandwidth required for query %d: ", q+1);
        scanf("%d%d", &n, &sum);

        int packets[n];
        int total_bandwidth = 0;

        printf("Enter the bandwidths of %d packets: ", n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &packets[i]);
            total_bandwidth += packets[i];
        }

        if(total_bandwidth < sum)
        {
            printf("Warning: Insufficient bandwidth!\n");
        }
        else
        {
            int temp_sum = 0;
            int count = 0;

            for(int i = 0; i < n; i++)
            {
                temp_sum += packets[i];
                count++;

                if(temp_sum >= sum)
                {
                    printf("Queried packets are: ");
                    for(int j = 0; j < count; j++)
                    {
                        printf("%d ", packets[j]);
                    }
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}