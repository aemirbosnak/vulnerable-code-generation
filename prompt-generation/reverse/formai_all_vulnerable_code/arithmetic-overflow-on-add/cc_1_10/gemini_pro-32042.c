//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point
{
	int x, y;
} point;

typedef struct line
{
	point a, b;
} line;

typedef struct circle
{
	point c;
	int r;
} circle;

int line_isect(line l1, line l2, point* p)
{
	int x1 = l1.a.x, y1 = l1.a.y, x2 = l1.b.x, y2 = l1.b.y, x3 = l2.a.x, y3 = l2.a.y, x4 = l2.b.x, y4 = l2.b.y;
	int d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if(d == 0)	return 0;
	int na = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3),
		nb = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
	p->x = x1 + na * (x2 - x1) / d;
	p->y = y1 + na * (y2 - y1) / d;
	return 1;
}

int circle_isect(circle c1, circle c2, point* p1, point* p2)
{
	int d = sqrt((c1.c.x - c2.c.x) * (c1.c.x - c2.c.x) + (c1.c.y - c2.c.y) * (c1.c.y - c2.c.y));
	if(d > c1.r + c2.r || d < abs(c1.r - c2.r))	return 0;
	int a = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d), b = d - a;
	p1->x = c1.c.x + (c2.c.x - c1.c.x) * a / d;
	p1->y = c1.c.y + (c2.c.y - c1.c.y) * a / d;
	p2->x = c1.c.x + (c2.c.x - c1.c.x) * b / d;
	p2->y = c1.c.y + (c2.c.y - c1.c.y) * b / d;
	return 1;
}

int polygon_isect(point* p, int n, line l, point* ip)
{
	int i, j, k, cnt = 0;
	for(i = 0; i < n; i++)
	{
		j = (i + 1) % n;
		if(line_isect(l, (line){p[i], p[j]}, ip))
		{
			if(cnt++ == 0)	*ip = *ip;
			else	return -1;
		}
	}
	return cnt;
}

int main()
{
	int n, i, j, k, x, y, r;
	point p[1000], ip;
	line l;
	circle c;
	scanf("%d", &n);
	for(i = 0; i < n; i++)	scanf("%d %d", &p[i].x, &p[i].y);
	scanf("%d %d %d", &l.a.x, &l.a.y, &l.b.x, &l.b.y);
	scanf("%d %d %d", &c.c.x, &c.c.y, &c.r);
	printf("%d\n", polygon_isect(p, n, l, &ip));
	printf("%d\n", circle_isect(c, (circle){ip, c.r}, &p[0], &p[1]));
	for(i = 0; i < 2; i++)	printf("%d %d\n", p[i].x, p[i].y);
	return 0;
}