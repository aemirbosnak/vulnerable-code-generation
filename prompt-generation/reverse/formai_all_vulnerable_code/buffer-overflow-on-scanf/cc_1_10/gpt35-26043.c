//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROWS 12           /* Number of rows in the maze */
#define COLUMNS 12        /* Number of columns in the maze */

char maze[ROWS][COLUMNS] = {   /* Your intricate labyrinth here! */
  {'#','#','#','#','#','#','#','#','#','#','#','#'},
  {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ','#'},
  {'#',' ','#',' ','#',' ','#',' ','#',' ',' ','#'},
  {'#',' ','#',' ','#',' ','#',' ','#',' ',' ','#'},
  {'#',' ','#',' ','#',' ','#',' ','#',' ',' ','#'},
  {'#',' ','#',' ','#',' ','#',' ','#',' ',' ','#'},
  {'#',' ','#',' ','#',' ','#',' ','#',' ',' ','#'},
  {'#',' ','#','#','#',' ','#','#','#',' ',' ','#'},
  {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
  {'#','#','#',' ','#',' ','#','#','#','#',' ','#'},
  {'#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#'},
  {'#','#','#','#','#','#','#','#','#','#','#','#'}
};

struct Node{      /* This node is where the travels through the maze begin */
    int xPos;
    int yPos;
    int stepNum;
    struct Node* parent;
};

int isValid(int x, int y){     /* Determine whether or not the given path is valid */
    if(x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
        return 0;
    }
    if(maze[x][y] == '#') {
        return 0;
    }
    return 1;
}

void printPath(struct Node *endNode){  /* Method that prints the path taken through the maze*/
    if(endNode == NULL) {
        return;
    }
    printPath(endNode->parent);
    printf("-> (%d,%d) ", endNode->xPos, endNode->yPos);
    return;
}

void findPath(int xStart, int yStart, int xFinish, int yFinish){ /* Find the path using the chosen starting and finishing points */
    int i;
    struct Node *startNode = (struct Node*) malloc(sizeof(struct Node));
    startNode->xPos = xStart;
    startNode->yPos = yStart;
    startNode->parent = NULL;
    startNode->stepNum = 0;
    struct Node nodes[ROWS*COLUMNS] = {{0}};
    int nodesHead = 0;
    int nodesTail = 0;
    nodes[nodesHead] = *startNode;
    nodesTail++;
    while(nodesHead != nodesTail){
        struct Node curr = nodes[nodesHead];
        if(curr.xPos == xFinish && curr.yPos == yFinish){
            printf("\nPath taken: ");
            printPath(&curr);
            printf("\nSteps taken: %d", curr.stepNum);
            return;
        }
        nodesHead++;
        if(isValid(curr.xPos+1, curr.yPos)){
            struct Node newNode;
            newNode.xPos = curr.xPos +1;
            newNode.yPos = curr.yPos;
            newNode.parent = &nodes[nodesHead-1];
            newNode.stepNum = curr.stepNum+1;
            nodes[nodesTail] = newNode;
            nodesTail++;
        }
        if(isValid(curr.xPos-1, curr.yPos)){
            struct Node newNode;
            newNode.xPos = curr.xPos -1;
            newNode.yPos = curr.yPos;
            newNode.parent = &nodes[nodesHead-1];
            newNode.stepNum = curr.stepNum+1;
            nodes[nodesTail] = newNode;
            nodesTail++;
        }
        if(isValid(curr.xPos, curr.yPos+1)){
            struct Node newNode;
            newNode.xPos = curr.xPos;
            newNode.yPos = curr.yPos+1;
            newNode.parent = &nodes[nodesHead-1];
            newNode.stepNum = curr.stepNum+1;
            nodes[nodesTail] = newNode;
            nodesTail++;
        } 
        if(isValid(curr.xPos, curr.yPos-1)){
            struct Node newNode;
            newNode.xPos = curr.xPos;
            newNode.yPos = curr.yPos-1;
            newNode.parent = &nodes[nodesHead-1];
            newNode.stepNum = curr.stepNum+1;
            nodes[nodesTail] = newNode;
            nodesTail++;
        }
    }
    printf("I'm sorry, I cannot find a path through this maze.");
    return;
}

int main(){ /*My program begins here!*/
    int xStart, yStart, xFinish, yFinish;
    printf("Please enter the starting coordinates in the form (x,y): ");
    scanf("(%d,%d)", &xStart, &yStart);
    printf("\nPlease enter the ending coordinates in the form (x,y): ");
    scanf("(%d,%d)", &xFinish, &yFinish);
    if(!isValid(xStart, yStart)){
        printf("\nInvalid starting point.");
        return 0;
    }
    if(!isValid(xFinish, yFinish)){
        printf("\nInvalid ending point.");
        return 0;
    }
    printf("\nFinding path through maze...\n");
    findPath(xStart, yStart, xFinish, yFinish);
    printf("\n");
    return 0;
}