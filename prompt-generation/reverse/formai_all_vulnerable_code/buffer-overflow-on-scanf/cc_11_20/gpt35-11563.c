//FormAI DATASET v1.0 Category: Physics simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pi=3.141;

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main()
{
    int num_players;
    double x[100],y[100],v[100],dir[100];
    double arena_x=500,arena_y=500;
    double ball_x,ball_y,ball_v=5,ball_dir;
    double goal_x1=50,goal_x2=450,goal_y1=225,goal_y2=275;
    double goalpost=5,post_offset=5;
    double player_radius=10,ball_radius=5;
    double time_step=0.1;
    int max_steps=10000;
    int ball_possession=-1;
    double pass_dist=50;
    srand(time(0));

    printf("Enter number of players (minimum 2, maximum 100): ");
    scanf("%d",&num_players);
    if(num_players<2 || num_players>100)
    {
        printf("Invalid number of players!");
        return 0;
    }

    //randomly place the players
    for(int i=0;i<num_players;i++)
    {
        x[i]=rand()%400+50;
        y[i]=rand()%400+50;
        v[i]=5;
        dir[i]=rand()%360;
    }

    //place the ball at the center
    ball_x=arena_x/2;
    ball_y=arena_y/2;
    ball_dir=rand()%360;

    //start the simulation
    for(int step=1;step<=max_steps;step++)
    {
        for(int i=0;i<num_players;i++)
        {
            //update player position and direction randomly
            x[i]+=v[i]*time_step*cos(dir[i]*pi/180);
            y[i]+=v[i]*time_step*sin(dir[i]*pi/180);
            if(x[i]<player_radius || x[i]>arena_x-player_radius) dir[i]=180-dir[i];
            if(y[i]<player_radius || y[i]>arena_y-player_radius) dir[i]=-dir[i];
            dir[i]+=rand()%30-15; //random directional change of 15 degrees
            if(dir[i]<0) dir[i]+=360;
            if(dir[i]>360) dir[i]-=360;

            //check if player has the ball
            if(dis(x[i],y[i],ball_x,ball_y)<player_radius+ball_radius)
            {
                ball_possession=i;
            }

            //if player has the ball, check for pass or goal
            if(ball_possession==i)
            {
                //check if player is near goal and can score
                if(ball_x>goal_x1+post_offset && ball_x<goal_x2-post_offset && ball_y>goal_y1 && ball_y<goal_y2)
                {
                    printf("Player %d has scored!\n",i+1);
                    return 0;
                }

                //check if player can pass to another player
                for(int j=0;j<num_players;j++)
                {
                    if(j!=i && dis(x[i],y[i],x[j],y[j])<pass_dist)
                    {
                        ball_possession=j;
                        break;
                    }
                }

                //if player cannot pass, continue with ball possession
                if(ball_possession==i)
                {
                    ball_x+=ball_v*time_step*cos(ball_dir*pi/180);
                    ball_y+=ball_v*time_step*sin(ball_dir*pi/180);
                    if(ball_x<ball_radius || ball_x>arena_x-ball_radius) ball_dir=180-ball_dir;
                    if(ball_y<ball_radius || ball_y>arena_y-ball_radius) ball_dir=-ball_dir;
                    ball_dir+=rand()%30-15; //random directional change of 15 degrees
                    if(ball_dir<0) ball_dir+=360;
                    if(ball_dir>360) ball_dir-=360;
                }
            }
        }
    }

    printf("Maximum number of simulation steps reached. Game ended in a draw!");
    return 0;
}