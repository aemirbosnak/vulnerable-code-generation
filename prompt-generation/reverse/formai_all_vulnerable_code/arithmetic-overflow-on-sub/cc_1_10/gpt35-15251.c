//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ConspiracyTheory {
    char *topic;
    char *description;
    char *evidence;
    char *source;
};

typedef struct ConspiracyTheory CT;

void sleep(int seconds) {
    clock_t start_time = clock();

    while ((clock() - start_time) < (seconds * CLOCKS_PER_SEC));
}

int main() {
    srand(time(NULL));
    int num_theories = rand() % 3 + 3; // generate 3-5 theories
    CT theories[num_theories];
    
    theories[0].topic = "Moon Landing Hoax";
    theories[0].description = "The 1969 Apollo moon landing was staged by the US government with the help of Hollywood.";
    theories[0].evidence = "The flag waving on the moon; the lack of stars in the photos; the shadows on the moon not being parallel; the apparent studio lighting in some of the photos and videos.";
    theories[0].source = "http://www.aulis.com/moon.htm";
    
    theories[1].topic = "Flat Earth";
    theories[1].description = "The earth is not a globe, but a flat disc, and everything we've been told about space exploration is a lie.";
    theories[1].evidence = "Lack of visible curve in photos and videos; the fact that water appears to be flat; the inability to feel earth's rotation.";
    theories[1].source = "https://www.tfes.org/";
    
    theories[2].topic = "9/11 Inside Job";
    theories[2].description = "The 9/11 attacks were a false flag operation carried out by the US government to justify going to war in the Middle East.";
    theories[2].evidence = "The fact that office fires cannot cause steel-framed buildings to collapse; the presence of molten steel in the wreckage; the lack of evidence for a plane at the Pentagon site.";
    theories[2].source = "https://www.ae911truth.org/";
    
    if (num_theories >= 4) {
        theories[3].topic = "Chemtrails";
        theories[3].description = "The trails left behind by planes in the sky are actually chemicals being sprayed by the government for secret purposes.";
        theories[3].evidence = "The persistent trails left by some planes; a decrease in air quality in areas where chemtrails have been reported; the lack of official response to the issue.";
        theories[3].source = "https://www.geoengineeringwatch.org/";
    }
    
    if (num_theories == 5) {
        theories[4].topic = "Reptilian Elite";
        theories[4].description = "The ruling class of the world are actually shape-shifting reptilian aliens who have infiltrated our governments and societies.";
        theories[4].evidence = "The belief that some people in power, such as Queen Elizabeth II and the Bush family, are part of the reptilian bloodline; the strange behavior of world leaders (e.g. blinking patterns, sudden shape shifts).";
        theories[4].source = "http://www.davidicke.com/";
    }
    
    printf("Generating conspiracy theories...\n\n");
    sleep(2);
    
    for (int i = 0; i < num_theories; i++) {
        printf("Theory #%d: %s\n", i+1, theories[i].topic);
        printf("\nDescription: %s\n", theories[i].description);
        printf("\nEvidence: %s\n", theories[i].evidence);
        printf("\nSource: %s\n", theories[i].source);
        printf("--------------------------------------------------\n");
        sleep(1);
    }
    
    printf("That's all the conspiracy theories for today. Stay woke!\n");
    
    return 0;
}