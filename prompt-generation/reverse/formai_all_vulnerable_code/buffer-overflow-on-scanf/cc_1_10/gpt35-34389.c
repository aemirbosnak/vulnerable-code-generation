//FormAI DATASET v1.0 Category: Browser Plugin ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PLUGIN_VERSION  "1.0.0"
#define PLUGIN_NAME     "Brave Rewards Plugin"

typedef struct {
    char* domain;
    char* status;
    float rewards;
} Website;

static Website websites[] = {
    {"google.com", "active", 0.0},
    {"facebook.com", "inactive", 0.0},
    {"wikipedia.org", "active", 0.0},
    {"twitter.com", "inactive", 0.0},
    {"reddit.com", "active", 0.0},
};

void updateRewards(char* domain, float newRewards) {
    for (int i=0; i<sizeof(websites)/sizeof(Website); i++) {
        if(strcmp(websites[i].domain, domain) == 0) {
            websites[i].rewards = newRewards;
            return;
        }
    }
}

Website getWebsiteInfo(char* domain) {
    Website website;
    for (int i=0; i<sizeof(websites)/sizeof(Website); i++) {
        if(strcmp(websites[i].domain, domain) == 0) {
            website = websites[i];
            break;
        }
    }

    return website;
}

void listActiveWebsites() {
    printf("Active websites: \n");

    for (int i=0; i<sizeof(websites)/sizeof(Website); i++) {
        if(strcmp(websites[i].status, "active") == 0) {
            printf("%s\n", websites[i].domain);
        }
    }
}

int main(void) {
    char website[100];
    float newRewards;

    printf("%s %s was successfully installed!\n", PLUGIN_NAME, PLUGIN_VERSION);
    printf("Type the domain to get rewards: ");

    scanf("%s", website);

    Website websiteInfo = getWebsiteInfo(website);

    if(strcmp(websiteInfo.status, "active") == 0) {
        printf("Current rewards for %s: %.2f\n", websiteInfo.domain, websiteInfo.rewards);

        printf("Enter new rewards amount: ");
        scanf("%f", &newRewards);

        updateRewards(websiteInfo.domain, newRewards);

        printf("Rewards for %s successfully updated!\n", websiteInfo.domain);
    } else {
        printf("Sorry, %s is not an eligible website for rewards.", websiteInfo.domain);
    }

    listActiveWebsites();

    return 0;
}