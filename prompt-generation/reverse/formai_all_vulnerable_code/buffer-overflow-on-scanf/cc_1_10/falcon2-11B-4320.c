//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_bags, num_carriers, carrier_id;
    int bag_id;
    char bag_tag[100];

    printf("Welcome to the paranoid airport baggage handling simulation!\n");
    printf("How many bags will be handled? ");
    scanf("%d", &num_bags);

    printf("How many carriers are available? ");
    scanf("%d", &num_carriers);

    printf("What is the carrier ID? ");
    scanf("%d", &carrier_id);

    printf("Enter the bag tags (comma separated): ");
    fgets(bag_tag, sizeof(bag_tag), stdin);

    for (int i = 0; i < num_bags; i++) {
        int bag_tag_length = strlen(bag_tag);
        int j = 0;

        while (j < bag_tag_length) {
            char temp_tag[100];
            strncpy(temp_tag, bag_tag, 99);
            if (temp_tag[99] == ',') {
                temp_tag[99] = '\0';
            } else {
                temp_tag[99] = ',';
            }

            int k = 0;

            while (k < num_carriers) {
                if (strcmp(temp_tag, carrier_id) == 0) {
                    printf("Bag %d handled by carrier %d\n", i + 1, carrier_id);
                    k++;
                    break;
                } else {
                    k++;
                }
            }

            j += strlen(temp_tag);
        }
    }

    printf("All bags have been handled!\n");

    return 0;
}