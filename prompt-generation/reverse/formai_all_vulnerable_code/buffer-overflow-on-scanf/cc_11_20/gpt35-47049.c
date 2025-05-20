//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>

int main() {
    int n, m, s, i, j, q, a, b, c;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the number of players: ");
    scanf("%d", &m);
    int pegs[m][n+1];
    for(i=0; i<m; i++){
        for(j=0; j<n+1; j++){
            pegs[i][j] = 0;
        }
    }
    for(i=1;i<=n;i++){
        pegs[0][i] = i;
    }
    s = 0;
    q = 0;
    while( q<n ){
        printf("\nPlayer %d, it's your turn...\n", s+1);
        printf("Enter 'a b' to move the top disk from peg a to peg b: ");
        scanf("%d %d", &a, &b);
        if (pegs[s][a] != 0){
            for(i=n;i>=1;i--){
                if (pegs[s][i] == 0) break;
            }
            c = i;
            for(;c>0;c--){
                if(pegs[s][c] > 0){
                    if(pegs[s][c] < pegs[s][a]){
                        printf("Cannot move disk!\n");
                        break;
                    }
                }
            }
            if (c == 0){
                for(i=1;i<=n;i++){
                    if(pegs[s][i] == 0){
                        q++;
                        pegs[s][i] = pegs[s][a];
                        pegs[s][a] = 0;
                        break;
                    }
                }
                printf("\nPlayer %d moved the top disk from peg %d to peg %d:\n", s+1, a, b );
                for(i=0; i<m; i++){
                    printf("Peg %d: ", i+1);
                    for(j=n; j>0; j--){
                        if(pegs[i][j]!=0) printf("%d ", pegs[i][j]);
                    }
                    printf("\n");
                }
                if (s == m-1) s = 0;
                else s++;
            }
        }
        else{
            printf("There is no disk on peg %d!\n", a);
        }
    }
    printf("Player %d completed the game!\n", s+1);
    return 0;
}